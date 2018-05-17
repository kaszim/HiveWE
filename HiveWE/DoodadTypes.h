#pragma once
class DoodadTypesModel : public QAbstractListModel {
public:
	DoodadTypesModel(QObject *parent = nullptr) : QAbstractListModel(parent) {};
protected:
	// Inherited via QAbstractListModel
	virtual Q_INVOKABLE int rowCount(const QModelIndex & parent = QModelIndex()) const override;
	virtual Q_INVOKABLE QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;
};

struct DoodadType {
	std::string doodID;
	std::string category;
	std::string tilesets;
	int tilesetSpecific;
	std::string file;
	std::string comment;
	std::string Name;
	std::string doodClass;
	std::string soundLoop;
	int selSize;
	float defScale;
	float minScale;
	float maxScale;
	bool canPlaceRandScale;
};

class DoodadTypes
{
private:
	slk::SLK doodads_slk;
	std::vector<DoodadType> types;

public:
	void load();
	DoodadTypes();
	~DoodadTypes();

	size_t size();
};
