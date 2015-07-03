/**
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */

#include "src/audit_log.h"

#include <yajl/yajl_tree.h>
#include <yajl/yajl_gen.h>
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>

#include <fstream>
#include <regex>


#define PARTS_CONSTAINS(a, c) \
    if (new_parts.find(toupper(a)) != std::string::npos \
        || new_parts.find(tolower(a)) != std::string::npos) { \
          this->m_parts = this->m_parts | c; \
    }

namespace ModSecurity {


bool AuditLog::setStorageDirMode(int permission) {
    this->m_storage_permission = permission;
    return true;
}


bool AuditLog::setFileMode(int permission) {
    this->m_file_permissions = permission;
    return true;
}


bool AuditLog::setStatus(AuditLogStatus new_status) {
    this->m_status = new_status;
    return true;
}


bool AuditLog::setRelevantStatus(const std::basic_string<char>& status) {
    this->m_relevant = status;
    return true;
}


bool AuditLog::setStorageDir(const std::basic_string<char>& path) {
    this->m_storage_dir = path;
    return true;
}


bool AuditLog::setFilePath1(const std::basic_string<char>& path) {
    this->m_path1 = path;
    return true;
}


bool AuditLog::setFilePath2(const std::basic_string<char>& path) {
    this->m_path2 = path;
    return true;
}


bool AuditLog::setParts(const std::basic_string<char>& new_parts) {
    PARTS_CONSTAINS('A', AAuditLogPart)
    PARTS_CONSTAINS('B', BAuditLogPart)
    PARTS_CONSTAINS('C', CAuditLogPart)
    PARTS_CONSTAINS('D', DAuditLogPart)
    PARTS_CONSTAINS('E', EAuditLogPart)
    PARTS_CONSTAINS('F', FAuditLogPart)
    PARTS_CONSTAINS('G', GAuditLogPart)
    PARTS_CONSTAINS('H', HAuditLogPart)
    PARTS_CONSTAINS('I', IAuditLogPart)
    PARTS_CONSTAINS('J', JAuditLogPart)
    PARTS_CONSTAINS('K', KAuditLogPart)
    PARTS_CONSTAINS('Z', ZAuditLogPart)

    return true;
}


bool AuditLog::setType(AuditLogType audit_type) {
    this->m_type = audit_type;
    return true;
}


bool AuditLog::init() {
     return true;
}


bool AuditLog::isRelevant(int status) {
    std::string sstatus = std::to_string(status);
    return std::regex_search(sstatus, std::regex(this->m_relevant)) != 0;
}


bool AuditLog::saveIfRelevant(Assay *assay) {
    return true;
}


std::string AuditLog::logfy(Assay *assay) {
    std::string log("ops");
    return log;
}


bool AuditLog::close() {
    return true;
}


}  // namespace ModSecurity
