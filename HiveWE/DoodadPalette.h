#pragma once

#include <QDialog>
#include "ui_DoodadPalette.h"

class DoodadPalette : public QDialog
{
	Q_OBJECT

public:
	DoodadPalette(QWidget *parent = nullptr);
	~DoodadPalette();

protected:


private:
	bool event(QEvent *e) override;
	Ui::DoodadPalette ui;
	DoodadTypesModel* model;

	DoodadBrush brush;
};
