class UserDTO {
  constructor(id) {
    this.id = id;
  }

  static convert2DTO(userEntity) {
    return new UserDTO(userEntity.id);
  }
}

module.exports = UserDTO;
