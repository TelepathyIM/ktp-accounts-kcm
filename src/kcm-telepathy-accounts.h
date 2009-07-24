/*
 * This file is part of telepathy-accounts-kcm
 *
 * Copyright (C) 2009 Collabora Ltd. <http://www.collabora.co.uk/>
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

#ifndef TELEPATHY_ACCOUNTS_KCM_KCM_TELEPATHY_ACCOUNTS_H
#define TELEPATHY_ACCOUNTS_KCM_KCM_TELEPATHY_ACCOUNTS_H

#include "ui_main-widget.h"

#include <KCModule>

#include <TelepathyQt4/AccountManager>

class AccountsListModel;
class AddAccountAssistant;

class KCategorizedSortFilterProxyModel;

namespace Tp {
    class PendingOperation;
}

class KCMTelepathyAccounts : public KCModule, Ui::MainWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(KCMTelepathyAccounts);

public:
    explicit KCMTelepathyAccounts(QWidget *parent = 0,
                                  const QVariantList& args = QVariantList());
    virtual ~KCMTelepathyAccounts();

public Q_SLOTS:
    virtual void load();

private Q_SLOTS:
    void onAccountManagerReady(Tp::PendingOperation *op);

    void onAddAccountClicked();
    void onAddAccountAssistantCancelled();

private:
    KCategorizedSortFilterProxyModel *m_accountsListProxyModel;
    Tp::AccountManagerPtr m_accountManager;
    AccountsListModel *m_accountsListModel;
    AddAccountAssistant *m_addAccountAssistant;
};


#endif // header guard
