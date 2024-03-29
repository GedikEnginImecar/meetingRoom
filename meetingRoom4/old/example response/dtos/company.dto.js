class CompanyDTO {
  constructor(id) {
    this.id = id;
  }

  static convert2DTO(companyEntity) {
    return new CompanyDTO(companyEntity.id);
  }
}
module.exports = CompanyDTO;
