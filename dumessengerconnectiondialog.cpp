#include "dumessengerconnectiondialog.h"
#include "ui_dumessengerconnectiondialog.h"

dumessengerconnectiondialog::dumessengerconnectiondialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dumessengerconnectiondialog)
{
    ui->setupUi(this);
}

dumessengerconnectiondialog::~dumessengerconnectiondialog()
{
    delete ui;
}

void dumessengerconnectiondialog::on_pb_accepter_2_clicked()
{
    mHostname=ui->hostname_2->text();
    mPort=ui->port_2->value();
    accept();
}

void dumessengerconnectiondialog::on_pb_cancel_2_clicked()
{
    reject();
}
