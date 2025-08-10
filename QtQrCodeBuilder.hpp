#pragma once
#include "qrcodegencpp/qrcodegen.hpp"

#include <QImage>
#include <QPainter>

using namespace qrcodegen;

class QtQrCodeBuilder
{
public:
    QtQrCodeBuilder();
    ~QtQrCodeBuilder();

    QrCode buildQrCode(const QString &data, QrCode::Ecc errorCorrection = QrCode::Ecc::MEDIUM);
    QImage drawQrCodeImage(const QrCode &qrCode, int size, int margin);
};