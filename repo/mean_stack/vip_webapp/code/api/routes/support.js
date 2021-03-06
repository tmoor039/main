var bodyParser = require('body-parser');    // get body-parser
var User = require('../models/users');
var Support = require('../models/support');
var mailingService = require('../services/mailing');

module.exports = function (app, express) {

    var supportRouter = express.Router();

    supportRouter.route('/recover/validate_email')
        .post(function (req, res) {
            User.findOne({ email: req.body.email }, '_id', function (err, record) {
                if (err) {
                    throw err
                }

                if (record && record._id) {
                    mailingService.sendPinRecoveryCode(record._id, function () {
                        console.log('mail sent')
                    }, function () {
                        console.log('error in mail sending')
                    })
                }
                var object = { validated: false }
                if (record && record._id) {
                    object.validated = true
                    object._id = record._id
                }
                res.json(object)
            })
        })

    supportRouter.route('/recover/verify_code').post(function (req, res) {
        var d = req.body
        mailingService.verifyPinRecoveryCode(d.user_id, d.code, function () {

            res.json({
                validated: true
            })

        }, function (err) {
            res.json({
                validated: false,
                error: err ? err.e : null
            })

        });

    });

    supportRouter.route('/recover/publish_password').post(function (req, res) {
        var d = req.body
        User.update({ _id: require('mongoose').Types.ObjectId(d.user_id) }, { password: d.password }, function (err, object) {
            if (err) {
                throw err
            }
            res.json({ validated: true })

            Support.remove({ user_id: d.user_id }, function (err) {
                if (err) {
                    throw err
                }
            })
        })

    });


    supportRouter.route('/recover/reset_pin').post(function (req, res) {

        if (req.body.client && req.body.password)

            Api.Private.UserAccounts.UpdateSettings(

                req.body.client, { password: req.body.password }, function () {
                    res.json({
                        validated: true
                    })
                }, next);

        else
            next()
    });


    return supportRouter;
};