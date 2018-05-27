#pragma once

class DoodadBrush : public Brush {
public:
	void set_position(const glm::vec2& position) override;
	void render(Terrain& terrain) const override;
	void apply() override;
	void set_doodad(DoodadType*);

protected:
	mutable Doodad doodad;
	glm::vec3 position;
};