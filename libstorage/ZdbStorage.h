/*
 * @CopyRight:
 * FISCO-BCOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FISCO-BCOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with FISCO-BCOS.  If not, see <http://www.gnu.org/licenses/>
 * (c) 2016-2019 fisco-dev contributors.
 */
/** @file ZdbStorage.h
 *  @author darrenyin
 *  @date 2019-04-24
 */

#pragma once

#include "Storage.h"
#include <json/json.h>
#include "SQLBasicAccess.h"


namespace dev
{
namespace storage
{
class ZdbStorage : public Storage
{
public:
    typedef std::shared_ptr<ZdbStorage> Ptr;

    ZdbStorage();
    virtual ~ZdbStorage(){};

    virtual Entries::Ptr select(h256 hash, int num, const std::string& table,
        const std::string& key, Condition::Ptr condition = nullptr) override;
    virtual size_t commit(h256 hash, int64_t num, const std::vector<TableData::Ptr>& datas,
        h256 const& blockHash) override;
    virtual bool onlyDirty() override;

public:
    void initSqlAccess(
        const std::string &dbtype,
        const std::string &dbip,
        uint32_t    dbport,
        const std::string &dbusername,
        const std::string &dbpasswd,
        const std::string &dbname,
        const std::string &dbcharset,
        uint32_t    initconnections,
        uint32_t    maxconnections
    );

private:
    SQLBasicAccess  m_oSqlBasicAcc;
};

}  // namespace storage

}  // namespace dev
