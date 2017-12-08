#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "field.h"
#include <QImage>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void startGame();


private slots:
    void on_startNewButton_clicked();

    void on_closeBurron_clicked();

    void on_useImagePushButton_clicked();

    void on_useNumbersPushButton_clicked();

private:
    Ui::Dialog *ui;
    Field field;
    QLabel* labels[16];
    void initLabels();

    bool useImage = false;

    void recalculateField();

    void keyPressEvent(QKeyEvent* pe);

    QImage img;

    QImage getImg(int i);
};

#endif // DIALOG_H
