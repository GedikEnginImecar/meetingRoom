class ModuleDTO {
  constructor(id) {
    this.id = id;
  }

  static convert2DTO(moduleEntity) {
    return new ModuleDTO(moduleEntity.id);
  }
}

module.exports = ModuleDTO;
