#pragma once

#include <QListView>

class DoodadListView : public QListView
{
	Q_OBJECT

signals:
	void selectedIndexChanged(const QModelIndex &current);

protected:
	void currentChanged(const QModelIndex &current, const QModelIndex &previous) override;

public:
	DoodadListView(QWidget *parent);
	~DoodadListView();
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
