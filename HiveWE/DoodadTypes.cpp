#include "stdafx.h"
#include "DoodadTypes.h"


DoodadTypes::DoodadTypes()
{
}

void DoodadTypes::load() {
	doodads_slk = slk::SLK("Doodads/Doodads.slk");
	const auto deg2rad = glm::pi<float>() / 180.f;
	for (auto y = 1; y < doodads_slk.rows; y++) {
		auto row = doodads_slk.table_data[y];
		types.emplace_back(DoodadType{
			row[0],
			row[1],
			row[2],
			row[4],
			row[5],
			std::stof(row[11]),
			std::stof(row[12]),
			std::stoi(row[20]),
			std::stof(row[27]) == -1.f ? 0 : std::stof(row[27]) * deg2rad
			});
		categories[types[y - 1].category].emplace_back(&types[y - 1]);
	}

	auto destructibles_slk = slk::SLK("Units/DestructableData.slk");

	for (auto y = 1; y < destructibles_slk.rows; y++) {
		auto row = destructibles_slk.table_data[y];
		types.emplace_back(DoodadType{
			row[0],
			row[1],
			row[2],
			row[4],
			row[9],
			std::stof(row[27]),
			std::stof(row[28]),
			std::stoi(row[21]),
			std::stof(row[25]) == -1.f ? 0 : std::stof(row[25]) * deg2rad
			});
		categories[types[y - 1].category].emplace_back(&types[y - 1]);
	}
}


DoodadTypes::~DoodadTypes()
{
}

size_t DoodadTypes::size()
{
	return types.size();
}

size_t DoodadTypes::size(std::string category)
{
	return categories[category].size();
}

DoodadType & DoodadTypes::operator[](size_t index)
{
	return types[index];
}

DoodadType& DoodadTypes::operator()(size_t index, std::string category) {
	return *categories[category][index];
}