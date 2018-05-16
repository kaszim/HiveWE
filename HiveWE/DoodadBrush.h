#pragma once

class DoodadBrush : public Brush {
public:
	void set_position(const glm::vec2& position) override;
	void render(Terrain& terrain) const override;
	void apply() override;

protected:
	glm::vec2 position;
};