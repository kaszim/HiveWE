#include "stdafx.h"
#include "DoodadListView.h"

DoodadListView::DoodadListView(QWidget *parent)
	: QListView(parent)
{
}

DoodadListView::~DoodadListView()
{
}

void DoodadListView::currentChanged(const QModelIndex & current, const QModelIndex & previous)
{
	emit selectedIndexChanged(current);
}

Q_INVOKABLE int DoodadTypesModel::rowCount(const QModelIndex &parent) const
{
	return doodadTypes.size();
}

Q_INVOKABLE QVariant DoodadTypesModel::data(const QModelIndex &index, int role) const
{
	if (role == Qt::DisplayRole) {
		return QString::fromStdString(doodadTypes[index.row()].comment);
	}
	else if (role == 1) {
		QVariant qv;
		qv.setValue(doodadTypes[index.row()]);
		return qv;
	}
	return QVariant();
}
