/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * LXDE-Qt - a lightweight, Qt based, desktop toolset
 * http://razor-qt.org
 *
 * Copyright: 2011 Razor team
 * Authors:
 *   Christian Surlykke <christian@surlykke.dk>
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */

#ifndef TRAYICON_H
#define TRAYICON_H

#include <QSystemTrayIcon>
#include <QMenu>

#include "batteryinfo.h"
#include "battery.h"
#include "iconproducer.h"
#include "../config/powermanagementsettings.h"

class TrayIcon : public QSystemTrayIcon
{
    Q_OBJECT

public:
    TrayIcon(Battery& battery, QObject *parent = 0);
    ~TrayIcon();

private slots:
    void batteryChanged();
    void settingsChanged();
    void iconThemeChanged();

    void onConfigureTriggered();
    void onAboutTriggered();
    void onDisableIconTriggered();

private:
    void updateToolTip();

    QMenu contextMenu;
    PowerManagementSettings mSettings;
    Battery& mBattery;
    IconProducer mIconProducer;
};

#endif // TRAYICON_H
