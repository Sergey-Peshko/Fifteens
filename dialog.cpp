#include "dialog.h"
#include "ui_dialog.h"
#include <QFileDialog>

#include <QImage>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    img("/home/siarhei/2.jpg")
{
    ui->setupUi(this);
    initLabels();

    std::vector<int> nums = field.getField();
    int row = 0, col = 0;
    for (int i = 0; i < field.SIZE; i++)
    {
        labels[i]->setText(QString::number(nums[i]));
        if (nums[i] == -1)
        {
            labels[i]->setStyleSheet("QLabel { background-color: white; }");
            labels[i]->setText("");
        }
        row = i / 4;
        col = i % 4;
        ui->grid->addWidget(labels[i],row,col);
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::startGame()
{
    field.initNew();
}

void Dialog::recalculateField()
{
    std::vector<int> nums = field.getField();
    for (int i = 0; i < field.SIZE; i++)
    {
        if(this->useImage){
            labels[i]->setPixmap(QPixmap::fromImage(getImg(nums[i])));
        }
        else{
            labels[i]->setText(QString::number(nums[i]));
        }
        labels[i]->setStyleSheet("QLabel { background-color: lightblue; }");
        if (nums[i] == -1)
        {
            labels[i]->setStyleSheet("QLabel { background-color: white; }");
            labels[i]->setText("");
        }
    }
}

void Dialog::keyPressEvent(QKeyEvent *pe)
{
    if (field.win())
    {
        ui->label->setText("You won!");
        return;
    }
    ui->label->setText("Use WASD to move white box");
    switch (pe->key()) {
    case Qt::Key_A:  // key left
        field.swap(lft);
        break;
    case Qt::Key_D:  // key right
        field.swap(rght);
        break;
    case Qt::Key_W:  // key up
        field.swap(up);
        break;
    case Qt::Key_S:  // key down
        field.swap(down);
        break;
    default:
        break;
    }
    recalculateField();
}
// 1  2  3  4
// 5  6  7  8
// 9  10 11 12
// 13 14 15
//
QImage Dialog::getImg(int i)
{
    if ( i == -1 ) {
        QImage kek(100, 100, QImage::Format_Grayscale8);
        kek.fill(255);
        return kek;
    }
    i = i - 1;
    return img.copy((i% 4) * 100, (i / 4) * 100, 100,100);
}

void Dialog::on_startNewButton_clicked()
{
    field.initNew();
    recalculateField();
}

void Dialog::on_closeBurron_clicked()
{
    window()->close();
}

void Dialog::initLabels()
{
    QFont font;
    font.setBold(true);
    font.setPixelSize(20);
    for (int i = 0; i < field.SIZE; i++)
    {
        labels[i] = new QLabel("+");
        labels[i]->setFont(font);
        labels[i]->setStyleSheet("QLabel { background-color: lightblue; }");
        labels[i]->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    }
}

void Dialog::on_useImagePushButton_clicked()
{
    this->useImage = true;
    recalculateField();
}

void Dialog::on_useNumbersPushButton_clicked()
{
     this->useImage = false;
    recalculateField();
}
