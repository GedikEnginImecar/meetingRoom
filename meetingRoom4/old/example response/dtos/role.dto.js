class RoleDTO {
  constructor(id) {
    this.id = id;
  }

  static convert2DTO(roleEntity) {
    return new RoleDTO(roleEntity.id);
  }
}

module.exports = RoleDTO;
