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

#include "kcm-telepathy-accounts.h"

#include "accounts-list-model.h"

#include <kcategorizedsortfilterproxymodel.h>
#include <kcategorydrawer.h>
#include <kgenericfactory.h>

#include <TelepathyQt4/Account>
#include <TelepathyQt4/PendingOperation>
#include <TelepathyQt4/PendingReady>


K_PLUGIN_FACTORY(KCMTelepathyAccountsFactory, registerPlugin<KCMTelepathyAccounts>();)
K_EXPORT_PLUGIN(KCMTelepathyAccountsFactory("telepathy_accounts", "kcm_telepathy_accounts"))


KCMTelepathyAccounts::KCMTelepathyAccounts(QWidget *parent, const QVariantList& args)
 : KCModule(KCMTelepathyAccountsFactory::componentData(), parent, args),
   m_accountsListProxyModel(0),
   m_accountsListModel(0)
{
    // Start up required telepathy components.
    startAccountManager();

    // Set up the UI stuff.
    setupUi(this);
    m_accountsListView->setCategoryDrawer(new KCategoryDrawer);

    m_accountsListModel = new AccountsListModel(this);
    m_accountsListProxyModel = new KCategorizedSortFilterProxyModel(this);
    m_accountsListProxyModel->setSourceModel(m_accountsListModel);
    m_accountsListView->setModel(m_accountsListProxyModel);
    m_accountsListProxyModel->setCategorizedModel(true);
}

KCMTelepathyAccounts::~KCMTelepathyAccounts()
{
    // TODO: Implement me!
}

void KCMTelepathyAccounts::load()
{
    // This slot is called whenever the configuration data in this KCM should
    // be reloaded from the store. We will not actually do anything here since
    // all changes that are made in this KCM are, at the moment, saved
    // immediately and cannot be reverted programatically.
    return;
}

void KCMTelepathyAccounts::startAccountManager()
{
    // This slot is called on construction to set up a telepathy accountmanager
    // instance.
    m_accountManager = Tp::AccountManager::create();

    connect(m_accountManager->becomeReady(), SIGNAL(finished(Tp::PendingOperation*)),
            this, SLOT(startAccountManagerFinished(Tp::PendingOperation*)));
}

void KCMTelepathyAccounts::startAccountManagerFinished(Tp::PendingOperation *op)
{
    if(op->isError())
    {
        kDebug() << "An error occurred making the AccountManager ready.";
        return;
    }
    else
    {
        kDebug() << "AccountManager became ready successfully.";
    }

    QList<Tp::AccountPtr> accounts = m_accountManager->allAccounts();
    foreach(Tp::AccountPtr account, accounts)
    {
        m_accountsListModel->addAccount(account);
    }
}


#include "kcm-telepathy-accounts.moc"

