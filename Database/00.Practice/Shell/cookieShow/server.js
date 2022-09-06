const express = require("express");

const app = express();

app.use(express.json());
app.use(express.urlencoded({ extended: true}));

app.listen(3000, () => console.log("server on"));

// dummy data
const shows = [
 { id: 1, name: "show1", reserveStartDate: "202208171530", reserveEndDate: "202208171630",
   seats: [false, false, false]
 },
 { id: 2, name: "show2", reserveStartDate: "202208171630", reserveEndDate: "202208171730",
   seats: [false, false, false]
 }
];

// 전체 조회
app.get("/shows", (req, res) => {
    res.json({ok: true, shows: shows});
})

// 단일 조회
app.get("/shows/:show_id", (req, res) => {
    const show_id = req.query.show_id
    const show = shows.filter(data => data.id == show_id);

    res.json({ok: true, show: show})
})

// 추가
app.post("/shows/add", (req, res) => {
    const { id, name, reserveStartDate, reserveEndDate, seats } = req.body
    const show = shows.concat({id, name, reserveStartDate, reserveEndDate, seats});

    res.json({ok: true, shows: show})
})

// 예약
app.patch("/show/reserve/:show_id", (req, res) => {
    const { show_id } = req.params
    const { show_seat } = req.body

    const show = shows.map(data => {
        // 이미 예약된 경우
        if(data.seats[show_seat] == true) {
          return
        }
        data.seats[show_seat] = true
        if(data.id == show_id) {
          return { show: data }
        }
    })

    res.json({ok: true, shows: show})
})
