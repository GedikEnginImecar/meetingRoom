class DepartmentDTO {
  constructor(id) {
    this.id = id;
  }

  static convert2DTO(departmentEntity) {
    return new DepartmentDTO(departmentEntity.id);
  }
}
module.exports = DepartmentDTO;
