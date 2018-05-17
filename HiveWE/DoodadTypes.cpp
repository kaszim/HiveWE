#include "stdafx.h"
#include "DoodadTypes.h"


DoodadTypes::DoodadTypes()
{
}

void DoodadTypes::load() {
	doodads_slk = slk::SLK("Doodads/Doodads.slk");
	for (auto y = 1; y < doodads_slk.rows; y++) {
		auto row = doodads_slk.table_data[y];
		auto x = 0;
		auto type = DoodadType{
			row[x++],
			row[x++],
			row[x++],
			std::stoi(row[x++]),
			row[x++],
			row[x++],
			row[x++],
			row[x++],
			row[x++],
			std::stoi(row[x++]),
			std::stof(row[x++]),
			std::stof(row[x++]),
			std::stof(row[x++]),
			static_cast<bool>(std::stoi(row[x++]))
		};
		types.emplace_back(type);
	}
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