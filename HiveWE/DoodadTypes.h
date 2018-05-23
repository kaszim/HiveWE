#pragma once
struct DoodadType {
	std::string doodID;
	std::string category;
	std::string tilesets;
	std::string file;
	std::string comment;
	float minScale;
	float maxScale;
	int numVar;
	float fixedRot;
};

class DoodadTypes
{
private:
	slk::SLK doodads_slk;
	std::vector<DoodadType> types;
	std::unordered_map<std::string, std::vector<DoodadType*> > categories;

public:
	void load();
	DoodadTypes();
	~DoodadTypes();

	size_t size();
	size_t size(std::string category);

	DoodadType& operator[](size_t index);
	DoodadType& operator()(size_t index, std::string category);
};
