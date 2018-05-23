#include "stdafx.h"
#include "DoodadPalette.h"

DoodadPalette::DoodadPalette(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	model = new DoodadTypesModel(map.doodad_types, this);
	ui.doodadListView->setModel(model);

	connect(ui.doodadListView, &DoodadListView::selectedIndexChanged, [this](const QModelIndex &index) {
		auto doodad = this->model->data(index, 1).value<DoodadType>();
		this->brush.set_doodad(&doodad);
	});

	setAttribute(Qt::WA_DeleteOnClose);
	show();

	brush.create();
	map.brush = &brush;
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
