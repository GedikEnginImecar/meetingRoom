class AppInfoDTO {
  constructor(id, os, version) {
    this.id = id;
    this.os = os;
    this.version = version;
  }

  static convert2DTO(appInfoEntity) {
    const records = new AppInfoDTO(appInfoEntity.id, appInfoEntity.os, appInfoEntity.version);
    return records;
  }
}

module.exports = AppInfoDTO;
