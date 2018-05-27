#include "stdafx.h"
#include "DoodadBrush.h"

void DoodadBrush::apply() {
	auto copy = doodad;
	copy.position *= 128.f;
	map.doodads.emplace_back(copy);
}

void DoodadBrush::set_doodad(DoodadType* dt) {
	doodad = Doodad{
		dt->doodID,
		0,
		this->position,
		glm::vec3(1.f, 1.f, 1.f),
		dt->fixedRot,
		DoodadState::visible_solid,
		255
	};
}

void DoodadBrush::set_position(const glm::vec2 & position) {
	auto center_position = glm::floor(position * 2.f) * .5f;
	float height = map.terrain.corner_height(static_cast<int>(center_position.x), static_cast<int>(center_position.y));
	this->position = glm::vec3(center_position, height);
	doodad.position = this->position;
}

void DoodadBrush::render(Terrain & terrain) const {
	if (doodad.id == "") {
		return;
	}
	doodad.matrix = glm::translate(glm::mat4(1.f), doodad.position);
	doodad.matrix = glm::scale(doodad.matrix, glm::vec3(1 / 128.f, 1 / 128.f, 1 / 128.f) * doodad.scale);
	doodad.matrix = glm::rotate(doodad.matrix, doodad.angle, glm::vec3(0, 0, 1));

	map.doodads.get_mesh(doodad.id, doodad.variation)->render_queue(doodad.matrix);
}
