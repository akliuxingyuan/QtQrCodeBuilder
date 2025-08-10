#include "QtQrCodeBuilder.hpp"

QtQrCodeBuilder::QtQrCodeBuilder() {};
QtQrCodeBuilder::~QtQrCodeBuilder() {};

QrCode QtQrCodeBuilder::buildQrCode(const QString &data, QrCode::Ecc errorCorrection)
{
    auto dataCStr = data.toUtf8().constData();
    return QrCode::encodeText(dataCStr, errorCorrection);
}

QImage QtQrCodeBuilder::drawQrCodeImage(const QrCode &qrCode, int size, int margin)
{
    const int qrCodeSize = qrCode.getSize();
    const int totalSize = qrCodeSize + 2 * margin;
    const int radio = size / totalSize;
    const int sizeRounded = totalSize * radio;

    QImage image(sizeRounded, sizeRounded, QImage::Format_ARGB32);
    QPainter painter(&image);
    painter.setPen(Qt::NoPen);

    // fill white backgroud
    painter.setBrush(Qt::white);
    painter.drawRect(0, 0, sizeRounded, sizeRounded);

    // fill black pixel, top-left (x=0,y=0)
    painter.setBrush(Qt::black);
    for (int y = 0; y < qrCodeSize; ++y)
    {
        for (int x = 0; x < qrCodeSize; ++x)
        {
            bool isBlack = qrCode.getModule(x, y);
            if (isBlack)
                painter.drawRect((x+margin)*radio, (y+margin)*radio, 1*radio, 1*radio);
        }
    }

    return image;
}