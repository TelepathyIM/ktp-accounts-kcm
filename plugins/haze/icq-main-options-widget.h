/*
 * This file is part of telepathy-accounts-kcm
 *
 * Copyright (C) 2011 Dominik Schmidt <kde@dominik-schmidt.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef KCMTELEPATHYACCOUNTS_PLUGIN_HAZE_ICQ_ACCOUNT_PARAMETERS_WIDGET_H
#define KCMTELEPATHYACCOUNTS_PLUGIN_HAZE_ICQ_ACCOUNT_PARAMETERS_WIDGET_H

#include "ui_icq-main-options-widget.h"

#include <KCMTelepathyAccounts/AbstractAccountParametersWidget>

class IcqMainOptionsWidget : public AbstractAccountParametersWidget
{
    Q_OBJECT
public:
    explicit IcqMainOptionsWidget(ParameterEditModel *model,
                                  QWidget *parent = 0);
    virtual ~IcqMainOptionsWidget();

    virtual QString defaultDisplayName() const override;
private:
    Q_DISABLE_COPY(IcqMainOptionsWidget)
    Ui::IcqMainOptionsWidget *m_ui;
};

#endif // header guard
