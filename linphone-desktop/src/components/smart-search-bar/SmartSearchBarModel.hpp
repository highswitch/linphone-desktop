/*
 * SmartSearchBarModel.hpp
 * Copyright (C) 2017  Belledonne Communications, Grenoble, France
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 *  Created on: February 2, 2017
 *      Author: Ronan Abhamon
 */

#ifndef SMART_SEARCH_BAR_MODEL_H_
#define SMART_SEARCH_BAR_MODEL_H_

#include "../sip-addresses/SipAddressesModel.hpp"

#include <QSortFilterProxyModel>

// =============================================================================

class SmartSearchBarModel : public QSortFilterProxyModel {
  Q_OBJECT;

public:
  SmartSearchBarModel (QObject *parent = Q_NULLPTR);
  ~SmartSearchBarModel () = default;

  QHash<int, QByteArray> roleNames () const override;

  Q_INVOKABLE void setFilter (const QString &pattern);

protected:
  bool filterAcceptsRow (int source_row, const QModelIndex &source_parent) const override;
  bool lessThan (const QModelIndex &left, const QModelIndex &right) const override;

private:
  int computeEntryWeight (const QVariantMap &entry) const;
  int computeStringWeight (const QString &string) const;

  QString m_filter;
  static const QRegExp m_search_separators;
};

#endif // SMART_SEARCH_BAR_MODEL_H_