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

Q_DECLARE_METATYPE(DoodadType)

class DoodadTypesModel : public QAbstractListModel {
public:
	DoodadTypesModel(DoodadTypes &dt, QObject *parent = nullptr) : doodadTypes{ dt }, QAbstractListModel(parent) {};
	virtual Q_INVOKABLE QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;
protected:
	// Inherited via QAbstractListModel
	virtual Q_INVOKABLE int rowCount(const QModelIndex & parent = QModelIndex()) const override;
private:
	DoodadTypes & doodadTypes;
};

