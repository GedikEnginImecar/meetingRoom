class ApiErrorLogDTO {
  constructor(...args) {
    args.forEach((arg) => {
      const propertyName = Object.keys(arg)[0];
      this[propertyName] = arg[propertyName];
    });
  }

  static convert2DTO(apiErrorLogEntity) {
    return new ApiErrorLogDTO(apiErrorLogEntity);
  }
}
module.exports = ApiErrorLogDTO;
