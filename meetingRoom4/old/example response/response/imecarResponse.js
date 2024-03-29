const imecarResponse = (records, paging = null) => {
  const responseJson = {
    header: {
      info: {},
      status: {},
      messages: {},
    },
    body: {
      data: {
        records: records,
      },
    },
  };
  if (paging) {
    responseJson.body.data.paging = paging;
  }
  return responseJson;
};

module.exports = imecarResponse;
