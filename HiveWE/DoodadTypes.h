#pragma once
class DoodadTypesModel : public QAbstractListModel {
public:
	DoodadTypesModel(QObject *parent = nullptr) : QAbstractListModel(parent) {};
protected:
	// Inherited via QAbstractListModel
	virtual Q_INVOKABLE int rowCount(const QModelIndex & parent = QModelIndex()) const override;
	virtual Q_INVOKABLE QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;
};

class DoodadTypes
{
public:
	DoodadTypes();
	~DoodadTypes();
};

