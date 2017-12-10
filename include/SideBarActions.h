#pragma once

#include <QAction>
#include <QHBoxLayout>
#include <QResizeEvent>
#include <QWidget>

#include "FlatButton.h"
#include "Menu.h"

#include "dialogs/JoinRoom.h"

class OverlayModal;

class SideBarActions : public QWidget
{
        Q_OBJECT

public:
        SideBarActions(QWidget *parent = nullptr);
        ~SideBarActions();

signals:
        void showSettings();
        void joinRoom(const QString &room);

protected:
        void resizeEvent(QResizeEvent *event) override;

private:
        QHBoxLayout *layout_;

        Menu *addMenu_;
        QAction *createRoomAction_;
        QAction *joinRoomAction_;

        QSharedPointer<OverlayModal> joinRoomModal_;
        QSharedPointer<dialogs::JoinRoom> joinRoomDialog_;

        FlatButton *settingsBtn_;
        FlatButton *createRoomBtn_;
        FlatButton *joinRoomBtn_;
};
