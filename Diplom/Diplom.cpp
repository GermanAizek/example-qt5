#include "Diplom.h"

Diplom::Diplom(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.elements, SIGNAL(currentIndexChanged(int)), this, SLOT(comboManager(int)));
	connect(ui.calcButton, SIGNAL(clicked()), this, SLOT(calculateButton()));
}

void Diplom::comboManager(int index)
{
	switch (index)
	{
	case 1: ui.city->setText("Тамбов"); break;
	case 2: ui.city->setText("Рязань"); break;
	case 3: ui.city->setText("Смоленск"); break;
	case 4: ui.city->setText("Тамбов"); break;
	case 5: ui.city->setText("Смоленск"); break;
	}

	QString cityText = ui.city->text();

	if (cityText == "Тамбов")
		ui.dateDelivery->setText("1");
	else if (cityText == "Рязань")
		ui.dateDelivery->setText("2");
	else if (cityText == "Смоленск")
		ui.dateDelivery->setText("3");
}

void Diplom::calculateButton()
{
	std::vector<QString> months = { "january", "february", "march", "april", "may", "june", "jule", "august", "september", "october", "november", "decamber" };
	int countDestroy = 0;
	
	for (int i = 0; i < months.size(); i++) {
		countDestroy += this->findChild<QLineEdit*>(months[i])->text().toInt();
	}

	ui.nextDestroy->setText(QString::number(round(countDestroy / months.size())));
}