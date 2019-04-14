#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Diplom.h"

#include <vector>

class Diplom : public QMainWindow
{
	Q_OBJECT

public:
	Diplom(QWidget *parent = Q_NULLPTR);

private:
	Ui::DiplomClass ui;

private slots:
	void comboManager(int index);
	void calculateButton();
};
