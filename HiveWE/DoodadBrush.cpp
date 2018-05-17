#include "stdafx.h"
#include "DoodadBrush.h"

void DoodadBrush::apply() {
	//auto doodad = map.doodads.get_doodad();
	//doodad.position = glm::vec3(position.x * 128.f, position.y * 128.f, 0.f);
	//map.doodads.insert(doodad);
}

void DoodadBrush::set_doodad(DoodadType* dt) {
	doodad = Doodad{
		dt->doodID,
		0,
		glm::vec3(position.x, position.y, 0.f),
		glm::vec3(1.f, 1.f, 1.f),
		5.7f,
		DoodadState::visible_solid,
		255,
	};
}

void DoodadBrush::set_position(const glm::vec2 & position) {
	this->position = position;
}

void DoodadBrush::render(Terrain & terrain) const {
	if (doodad.id == "") {
		return;
	}
	auto matrix = glm::translate(glm::mat4(1.f), glm::vec3(position, 0.f));
	matrix = glm::scale(matrix, glm::vec3(1 / 128.f, 1 / 128.f, 1 / 128.f) * doodad.scale);
	matrix = glm::rotate(matrix, doodad.angle, glm::vec3(0, 0, 1));

	map.doodads.get_mesh(doodad.id, doodad.variation)->render_queue(matrix);
}
