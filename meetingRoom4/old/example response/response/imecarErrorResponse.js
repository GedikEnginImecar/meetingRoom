const imecarErrorResponse = (err) => {
  const responseJson = {
    header: {
      info: {},
      status: {},
      messages: {
        level: 1,
        code: err.apiErrorCode,
        description: err.errName,
        data: err.message,
      },
    },
    body: {},
  };

  return responseJson;
};
module.exports = imecarErrorResponse;
