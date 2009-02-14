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

#include "accounts-list-model.h"

#include "account-item.h"

#include <kdebug.h>

#include <TelepathyQt4/Client/Account>

AccountsListModel::AccountsListModel(QObject *parent)
 : QAbstractListModel(parent)
{
    m_unreadyAccounts.clear();
    m_readyAccounts.clear();
}

AccountsListModel::~AccountsListModel()
{
    // TODO: Implement me!
}

int AccountsListModel::rowCount(const QModelIndex &index) const
{
    if(index == QModelIndex())
    {
       return m_readyAccounts.size();
    }

    return 0;
}

QVariant AccountsListModel::data(const QModelIndex &index, int role) const
{
    // FIXME: This is a basic implementation just so I can see what's going
    // on while developing this code further. Needs expanding.
    if(role == Qt::DisplayRole)
    {
        return QVariant(m_readyAccounts.at(index.row())->account()->displayName());
    }

    return QVariant();
}

void AccountsListModel::addAccount(Telepathy::Client::Account *account)
{
    kDebug() << "Creating a new AccountItem from account:" << account;
    // Check if the account is already in the model.
    bool found = false;

    foreach(const AccountItem* ai, m_unreadyAccounts)
    {
        if(ai->account() == account)
        {
            found = true;
            break;
        }
    }
    if(!found)
    {
        foreach(const AccountItem* ai, m_readyAccounts)
        {
            if(ai->account() == account)
            {
                found = true;
                break;
            }
        }
    }

    if(found)
    {
       kDebug() << "Requested to add account"
               << account
               << "to model, but it is already present. Doing nothing.";
   }
   else
   {
       AccountItem *item = new AccountItem(account, this);
       m_unreadyAccounts.append(item);
       connect(item, SIGNAL(ready()), this, SLOT(onAccountItemReady()));
       connect(item, SIGNAL(removed()), this, SLOT(onAccountItemRemoved()));
       connect(item, SIGNAL(updated()), this, SLOT(onAccountItemUpdated()));
   }
}

void AccountsListModel::onAccountItemReady()
{
    // TODO: Implement me!
}

void AccountsListModel::onAccountItemRemoved()
{
    // TODO: Implement me!
}

void AccountsListModel::onAccountItemUpdated()
{
    // TODO: Implement me!
}


#include "accounts-list-model.moc"

