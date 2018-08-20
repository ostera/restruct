// Generated by BUCKLESCRIPT VERSION 4.0.5, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var CamlinternalLazy = require("bs-platform/lib/js/camlinternalLazy.js");
var ReStruct_Lazy_List$Restruct = require("./ReStruct_Lazy_List.bs.js");

var empty = /* record */[
  /* f_size */0,
  /* f : Nil */0,
  /* r_size */0,
  /* r : Nil */0
];

function isEmpty(param) {
  return param[/* f_size */0] === 0;
}

function push(param, e) {
  var r = param[/* r */3];
  var q = /* record */[
    /* f_size */param[/* f_size */0],
    /* f */param[/* f */1],
    /* r_size */param[/* r_size */2] + 1 | 0,
    /* r */Block.__(246, [(function () {
            return /* Cons */[
                    e,
                    r
                  ];
          })])
  ];
  var r_size = q[/* r_size */2];
  var f_size = q[/* f_size */0];
  var match = r_size <= f_size;
  if (match) {
    return q;
  } else {
    return /* record */[
            /* f_size */f_size + r_size | 0,
            /* f */ReStruct_Lazy_List$Restruct.append(q[/* f */1], ReStruct_Lazy_List$Restruct.reverse(q[/* r */3])),
            /* r_size */0,
            /* r : Nil */0
          ];
  }
}

function head(param) {
  var f = param[/* f */1];
  var tag = f.tag | 0;
  var match = tag === 250 ? f[0] : (
      tag === 246 ? CamlinternalLazy.force_lazy_block(f) : f
    );
  if (match) {
    return Js_primitive.some(match[0]);
  }
  
}

function tail(param) {
  var f = param[/* f */1];
  var tag = f.tag | 0;
  var match = tag === 250 ? f[0] : (
      tag === 246 ? CamlinternalLazy.force_lazy_block(f) : f
    );
  if (match) {
    return /* record */[
            /* f_size */param[/* f_size */0] - 1 | 0,
            /* f */match[1],
            /* r_size */param[/* r_size */2],
            /* r */param[/* r */3]
          ];
  }
  
}

var M = /* module */[
  /* empty */empty,
  /* isEmpty */isEmpty,
  /* push */push,
  /* head */head,
  /* tail */tail
];

exports.M = M;
exports.empty = empty;
exports.isEmpty = isEmpty;
exports.push = push;
exports.head = head;
exports.tail = tail;
/* No side effect */