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
		dt->numVar
	};
}

void DoodadBrush::set_position(const glm::vec2 & position) {
	this->position = position;
}

void DoodadBrush::render(Terrain & terrain) const {
	/*auto i = map.doodads.get_doodad();
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(position.x, position.y, 0.f));
	model = glm::scale(model, glm::vec3(1 / 128.f, 1 / 128.f, 1 / 128.f) * i.scale);
	model = glm::rotate(model, i.angle, glm::vec3(0, 0, 1));

	map.doodads.get_mesh()->render_queue(camera.projection_view * model);*/
}
