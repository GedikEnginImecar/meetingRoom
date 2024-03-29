module.exports = (sequelize, DataTypes) => {
	const User = sequelize.define(`user`, {
		userID: {
			type: DataTypes.INTEGER,
			primaryKey: true,
			autoIncrement: true,
		},
		permission: {
			type: DataTypes.INTEGER,
			allowNull: false,
		},
		username: {
			type: DataTypes.TEXT,
			allowNull: false,
		},
		password: {
			type: DataTypes.TEXT,
			allowNull: false,
		},
		department: {
			type: DataTypes.TEXT,
			allowNull: false,
		},
	});

	return User;
};

// version using validator instead of express-validator
// const validator = require("validator");
// module.exports = (sequelize, DataTypes) => {
// 	const User = sequelize.define(`user`, {
// 		userID: {
// 			type: DataTypes.INTEGER,
// 			primaryKey: true, // This specifies id as the primary key
// 			autoIncrement: true, // Assuming it's an auto-incrementing field
// 		},
// 		permission: {
// 			// access level
// 			type: DataTypes.INTEGER,
// 			allowNull: false,
// 		},
// 		username: {
// 			type: DataTypes.TEXT,
// 			allowNull: false,
// 			validate: {
// 				isIn: [[0, 1, 2, 3]],
// 			},
// 		},
// 		password: {
// 			type: DataTypes.TEXT,
// 			allowNull: false,
// 		},
// 		department: {
// 			type: DataTypes.TEXT,
// 			allowNull: false,
// 			validate: {
// 				isIn: [["software", "engineering", "design", "owner"]],
// 			},
// 		},
// 	});

// 	return User;
// };
