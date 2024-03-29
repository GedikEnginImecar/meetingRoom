class PermissionDTO {
  constructor(id) {
    this.id = id;
  }

  static convert2DTO(permissionEntity) {
    return new PermissionDTO(permissionEntity.id);
  }
}

module.exports = PermissionDTO;
