#include "stdafx.h"
#include "DoodadTypes.h"


DoodadTypes::DoodadTypes()
{
}


DoodadTypes::~DoodadTypes()
{
}

Q_INVOKABLE int DoodadTypesModel::rowCount(const QModelIndex &parent) const
{
	return 1;
}

Q_INVOKABLE QVariant DoodadTypesModel::data(const QModelIndex &index, int role) const
{
	if (role == Qt::DisplayRole) {
		return "Hello World";
	}
	return QVariant();
}
