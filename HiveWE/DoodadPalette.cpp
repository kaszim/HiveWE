#include "stdafx.h"
#include "DoodadPalette.h"

DoodadPalette::DoodadPalette(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	setAttribute(Qt::WA_DeleteOnClose);
	show();

	brush.create();
	map.brush = &brush;

	model = new DoodadTypesModel(map.doodad_types, this);
	/*model = new QStringListModel(this);

	QStringList list;
	for (auto&& row : map.doodads.get_doodads_slk().table_data) {
	list << QString::fromStdString(row[5]);
	}
	model->setStringList(list);*/

	ui.doodadListView->setModel(model);
}

DoodadPalette::~DoodadPalette()
{
	map.brush = nullptr;
	delete model;
}

bool DoodadPalette::event(QEvent *e) {
	if (e->type() == QEvent::WindowActivate) {
		map.brush = &brush;
	}
	return QWidget::event(e);
}
