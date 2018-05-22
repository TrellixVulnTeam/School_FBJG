window.addEventListener("load", function () {
    //Guns

    // Blaster START
    var intervalBValue = 200, fireB = false, intervalB, gunSet=0, blasterSpeed=40;
    // Blaster END

    // Cannon START
    // Cannon END

    // Scoreboard START
    var first, second, third, fourth, fifth;
    // Scoreboard END

    //Stage
    var st, p = true, gameStage = 1, temp, health = 0, tryAgain = false;
    //Enable sound
    if (sessionStorage.getItem("sounds") == null) {
        sessionStorage.setItem("sounds", true);
    }
    if (sessionStorage.getItem("difficulty") == null) {
        sessionStorage.setItem("difficulty", "medium");
    }
    var sounds = sessionStorage.getItem("sounds") == 'true' ? true : false;
    //Player position
    var pPx, pPy;

    var op = true, createdHud = false;

    // Buttons
    function continueB() {
        if (p) {
            if (Q.stage(1) != null) {
                Q.stage(1).unpause();
                p = false;
                Q.clearStage(2);
                if (!createdHud) {
                    Q.stageScene("hud", 3);
                    createdHud = !createdHud;
                }
                
                Q.input.touchControls({
                    controls:
                        [['left', '<'],
                        ['fire', 'F'],
                        ['menuB', 'M'],
                        ['right', '>']]
                });
                
                gameSounds();
                if (fireB) {
                    intervalB = window.setInterval(fire, intervalBValue);
                }
            }
        }
    }

    function menuB() {
        if (!p) {
            if (Q.stage(1) != null) {
                Q.stage(1).pause();

                p = true;
                //Q.clearStage(2);
                //Q.clearStage(3);
                Q.stageScene("menu", 2);
                Q.input.disableTouchControls();

                menuSounds();

                if (fireB) {
                    clearInterval(intervalB);
                }
            }
        }
    }

    //Sounds
    function menuSounds() {
        if (sounds) {
            Q.audio.stop('bgSound1.wav', { loop: true });
            Q.audio.play('bgSound1.wav', { loop: true });
            Q.audio.stop('bgSound2.wav', { loop: true });
            Q.audio.stop('bgSound3.wav', { loop: true });
        }
    }

    function gameSounds() {
        if (sounds) {
            Q.audio.stop('bgSound1.wav', { loop: true });
            Q.audio.play('bgSound2.wav', { loop: true });
            Q.audio.play('bgSound3.wav', { loop: true });
            //Q.audio.play('bgSound4.wav', { loop: true });
        }
    }

    function disableSounds() {
        Q.audio.stop('bgSound1.wav', { loop: true });
        Q.audio.stop('bgSound2.wav', { loop: true });
        Q.audio.stop('bgSound3.wav', { loop: true });
    }

    function fire() {
        if (Q.stage(1).paused != null) {
            if (sounds) {
                var b = Q.audio.play('blaster1.wav');
            }
            if (gunSet == 1) {
                st.insert(new Q.Blaster({ x: pPx + 10 }));
                st.insert(new Q.Blaster({ x: pPx - 10 }));
            } else {
                st.insert(new Q.Blaster());
            }
        } else {
            p = true;
            fireB = false;
            clearInterval(intervalB);
        }
    }

    function saveScore() {
        var scoreFinal = Q("UI.Text", 3).items[0];

        if (localStorage.getItem("scoreFirst") == "---" || parseInt(scoreFinal.p.label) > parseInt(localStorage.getItem("scoreFirst"))) {
            localStorage.setItem("scoreFifth", localStorage.getItem("scoreFourth"));
            localStorage.setItem("scoreFourth", localStorage.getItem("scoreThird"));
            localStorage.setItem("scoreThird", localStorage.getItem("scoreSecond"));
            localStorage.setItem("scoreSecond", localStorage.getItem("scoreFirst"));
            localStorage.setItem("scoreFirst", scoreFinal.p.label);
        } else if (localStorage.getItem("scoreSecond") == "---" || parseInt(scoreFinal.p.label) > parseInt(localStorage.getItem("scoreSecond"))) {
            localStorage.setItem("scoreFifth", localStorage.getItem("scoreFourth"));
            localStorage.setItem("scoreFourth", localStorage.getItem("scoreThird"));
            localStorage.setItem("scoreThird", localStorage.getItem("scoreSecond"));
            localStorage.setItem("scoreSecond", scoreFinal.p.label);
        } else if (localStorage.getItem("scoreThird") == "---" || parseInt(scoreFinal.p.label) > parseInt(localStorage.getItem("scoreThird"))) {
            localStorage.setItem("scoreFifth", localStorage.getItem("scoreFourth"));
            localStorage.setItem("scoreFourth", localStorage.getItem("scoreThird"));
            localStorage.setItem("scoreThird", scoreFinal.p.label);
        } else if (localStorage.getItem("scoreFourth") == "---" || parseInt(scoreFinal.p.label) > parseInt(localStorage.getItem("scoreFourth"))) {
            localStorage.setItem("scoreFifth", localStorage.getItem("scoreFourth"));
            localStorage.setItem("scoreFourth", scoreFinal.p.label);
        } else if (localStorage.getItem("scoreFifth") == "---" || parseInt(scoreFinal.p.label) > parseInt(localStorage.getItem("scoreFifth"))) {
            localStorage.setItem("scoreFifth", scoreFinal.p.label);
        }

        first = localStorage.getItem("scoreFirst");
        second = localStorage.getItem("scoreSecond");
        third = localStorage.getItem("scoreThird");
        fourth = localStorage.getItem("scoreFourth");
        fifth = localStorage.getItem("scoreFifth");
    }

    var Q = Quintus({ audioSupported: ['wav, mp3'] });

    Q = window.Q = Quintus({ development: true })
        .include("Audio, Sprites, Scenes, Input, 2D, Anim, UI, Touch")
        .include("Enemy, Asteroid, Boss, powerUp")
        .setup({ maximize: true, width: window.innerWidth, height: window.innerHeight })
        .enableSound()
        .touch();
        //.controls();

    //    Add in the default keyboard controls
    //    along with joypad controls for touch
    Q.input.keyboardControls({
        LEFT: "left",
        RIGHT: "right",
        SPACE: "fire",
        27: "menuB",
        13: "continue"
    });
    Q.gravityY = 0;
    Q.gravityX = 0;

    Q.SPRITE_PLAYER = 1;
    Q.SPRITE_FRIENDLY = 8;
    Q.SPRITE_ENEMY = 16;
    Q.SPRITE_POWERUP = 32;

    //Q.input.joypadControls();

    //************************//
    //Load and start the level//
    //************************//
    Q.load("bgSound1.wav, bgSound2.wav, bgSound3.wav, bgSound4.wav, blaster.wav, blaster1.wav, aliens-radio-chatter1.wav, aliens-radio-chatter2.wav, aliens-radio-chatter3.wav, aliens-radio-chatter4.wav, aliens-radio-chatter5.wav, aliens-radio-chatter6.wav, aliens-radio-chatter7.wav, aliens-radio-chatter8.wav, aliens-radio-chatter9.wav, aliens-radio-chatter10.wav, aliens-radio-chatter11.wav, aliens-radio-chatter12.wav, explosion.wav, explosion2.wav, explosion3.wav, alert.wav, gameOver.wav, hit1.wav, hit2.wav, hit3.wav, hit4.wav, firstMiniBoss1.wav, firstMiniBoss2.wav, firstBoss.wav, bossLaser.wav, bg.jpg, bg1.jpg, bg2.jpg, rocket.png, bullet.png, bulletE.png, plusBlaster.png, plusBlasterSpeed.png, Enemy1.png, Enemy2.png, asteroid_belt.png, asteroid_belt2.png, asteroids.png, asteroids.json", function () {
        Q.compileSheets("asteroids.png", "asteroids.json");
        menuSounds();
        if (localStorage.getItem("scoreFirst") == null) {
            localStorage.setItem("scoreFirst", "---");
        }
        if (localStorage.getItem("scoreSecond") == null) {
            localStorage.setItem("scoreSecond", "---");
        }
        if (localStorage.getItem("scoreThird") == null) {
            localStorage.setItem("scoreThird", "---");
        }
        if (localStorage.getItem("scoreFourth") == null) {
            localStorage.setItem("scoreFourth", "---");
        }
        if (localStorage.getItem("scoreFifth") == null) {
            localStorage.setItem("scoreFifth", "---");
        }
        
        first = localStorage.getItem("scoreFirst");
        second = localStorage.getItem("scoreSecond");
        third = localStorage.getItem("scoreThird");
        fourth = localStorage.getItem("scoreFourth");
        fifth = localStorage.getItem("scoreFifth");

        Q.stageScene("menu", 2);
        Q.stageScene("level1", 1);
        Q.stage(1).pause();
    });

    Q.scene('end', function (stage) {
        var container = Q.stage(3).insert(new Q.UI.Container({
            x: 0, y: 0
        }));
        var score = container.insert(new Q.UI.Text({
            x: window.innerWidth / 2, y: 200,
            label: "YOU ARE DEAD", color: "white", align: "right"
        }));
        stage.insert(new Q.UI.Button({
            label: "  TRY AGAIN  ",
            y: 250,
            x: Q.width / 2,
            fill: "#F5F5F5",
            //border: 1,
            scale: 0.8
        }, function () {
            Q.audio.stop();
            tryAgain = true;
            Q.clearStages();
            st = null;
            intervalBValue = 200, fireB = false, intervalB, gunSet = 0, blasterSpeed = 40;
            op = true, createdHud = false;
            p = true, gameStage = 1, temp, health = 0;
            menuSounds();
            Q.stageScene("menu", 2);
            Q.stageScene("level1", 1);
            Q.stage(1).pause();
        }));

        stage.insert(new Q.UI.Button({
            label: "SAVE SCORE",
            y: 300,
            x: Q.width / 2,
            fill: "#F5F5F5",
            //border: 1,
            scale: 0.8
        }, function () {
            saveScore();
            tryAgain = true;
            Q.clearStages();
            st = null;
            intervalBValue = 200, fireB = false, intervalB, gunSet = 0, blasterSpeed = 40;
            op = true, createdHud = false;
            p = true, gameStage = 1, temp, health = 0;
            menuSounds();
            Q.stageScene("scoreboard", 2);
            Q.stageScene("level1", 1);
            Q.stage(1).pause();
        }));
    });

    Q.scene('scoreboard', function (stage) {
        stage.insert(new Q.UI.Text({
            x: window.innerWidth / 2, y: window.innerHeight * 3 / 16,
            label: "TOP 5", color: "white", align: "right"
        }));
        stage.insert(new Q.UI.Text({
            x: window.innerWidth / 2, y: (window.innerHeight + 5) * 3 / 16,
            label: "_______________", color: "white", align: "right"
        }));
        
        var firstT = stage.insert(new Q.UI.Text({
            x: window.innerWidth / 2, y: window.innerHeight * 4 / 16,
            label: first, color: "white", align: "right"
        }));
        
        var secondT = stage.insert(new Q.UI.Text({
            x: window.innerWidth / 2, y: window.innerHeight * 5 / 16,
            label: second, color: "white", align: "right"
        }));

        var thirdT = stage.insert(new Q.UI.Text({
            x: window.innerWidth / 2, y: window.innerHeight * 6 / 16,
            label: third, color: "white", align: "right"
        }));

        var fourthT = stage.insert(new Q.UI.Text({
            x: window.innerWidth / 2, y: window.innerHeight * 7 / 16,
            label: fourth, color: "white", align: "right"
        }));

        var fifthT = stage.insert(new Q.UI.Text({
            x: window.innerWidth / 2, y: window.innerHeight * 8 / 16,
            label: fifth, color: "white", align: "right"
        }));
        
        stage.insert(new Q.UI.Button({
            label: "        BACK       ",
            y: window.innerHeight * 10 / 16,
            x: Q.width / 2,
            fill: "#F5F5F5",
            //border: 1,
            scale: 0.8
        }, function () {
            Q.clearStage(2);
            //Q.clearStage(3);
            Q.stageScene("menu", 2);  
        }));
    });

    // Starting scene MENU
    Q.scene('menu', function (stage) {
        stage.insert(new Q.UI.Button({
            label: "        PLAY        ",
            y: window.innerHeight * 5 / 14,
            x: Q.width / 2,
            fill: "#F5F5F5",
            //border: 1,
            scale: 0.8
        }, function () {
            continueB();
        }));

        stage.insert(new Q.UI.Button({
            label: "    OPTIONS     ",
            y: window.innerHeight * 6 / 14,
            x: Q.width / 2,
            fill: "#F5F5F5",
            //border: 1,
            scale: 0.8
        }, function () {
            Q.clearStage(2);
            //Q.clearStage(3);
            Q.stageScene("option", 2);
        }));

        stage.insert(new Q.UI.Button({
            label: "SCOREBOARD",
            y: window.innerHeight * 7 / 14,
            x: Q.width / 2,
            fill: "#F5F5F5",
            //border: 1,
            scale: 0.8
        }, function () {
            Q.clearStage(2);
            //Q.clearStage(3);
            Q.stageScene("scoreboard", 2);
        }));
        
        /*stage.insert(new Q.UI.HTMLElement({
            
        }));*/
    });


    //Scene Option
    Q.scene('option', function (stage) {
        var enemy = Q("Enemy1");
        var sound = stage.insert(new Q.UI.Button({
            label: "     SOUNDS     ",
            y: window.innerHeight * 5 / 14,
            x: Q.width / 2,
            fill: "#F5F5F5",
            //border: 1,
            scale: 0.8
        }, function () {
            sounds = !sounds;
            enemy.sounds = sounds;
            if (typeof (Storage) !== "undefined") {
                sessionStorage.setItem("sounds", sounds);
            } else {
                console.log("oopsie");
            }
            if (sounds === true) {
                menuSounds();
                sound.p.label = "SOUNDS ON";
            } else {
                Q.audio.stop();
                sound.p.label = "SOUNDS OFF";
            }
            }));
        stage.insert(new Q.UI.Button({
            label: "  DIFFICULTY  ",
            y: window.innerHeight * 6 / 14,
            x: Q.width / 2,
            fill: "#F5F5F5",
            //border: 1,
            scale: 0.8
        }, function () {
            Q.clearStage(2);
            //Q.clearStage(3);
            Q.stageScene("difficulty", 2);  
        }));

        if (sounds === true) {
            sound.p.label = "SOUNDS ON";
        } else {
            sound.p.label = "SOUNDS OFF";
        }
        stage.insert(new Q.UI.Button({
            label: "        BACK       ",
            y: window.innerHeight * 7 / 14,
            x: Q.width / 2,
            fill: "#F5F5F5",
            //border: 1,
            scale: 0.8
        }, function () {
            Q.clearStage(2);
            //Q.clearStage(3);
            Q.stageScene("menu", 2);  
        }));
    });

    Q.scene('difficulty', function (stage) {

        var easy = stage.insert(new Q.UI.Button({
            label: "        EASY       ",
            y: window.innerHeight * 5 / 14,
            x: Q.width / 2,
            fill: "#F5F5F5",
            //border: 1,
            scale: 0.8
        }, function () {
            easy.p.fill = "#808080";
            medium.p.fill = "#F5F5F5";
            hard.p.fill = "#F5F5F5";
            sessionStorage.setItem("difficulty", "easy");
            }));

        var medium = stage.insert(new Q.UI.Button({
            label: "      MEDIUM     ",
            y: window.innerHeight * 6 / 14,
            x: Q.width / 2,
            fill: "#808080",
            //border: 1,
            scale: 0.8
        }, function () {
            easy.p.fill = "#F5F5F5";
            medium.p.fill = "#808080";
            hard.p.fill = "#F5F5F5";
            sessionStorage.setItem("difficulty", "medium");
            }));

        var hard = stage.insert(new Q.UI.Button({
            label: "        HARD       ",
            y: window.innerHeight * 7 / 14,
            x: Q.width / 2,
            fill: "#F5F5F5",
            //border: 1,
            scale: 0.8
        }, function () {
            easy.p.fill = "#F5F5F5";
            medium.p.fill = "#F5F5F5";
            hard.p.fill = "#808080";
            sessionStorage.setItem("difficulty", "hard");
        }));

        stage.insert(new Q.UI.Button({
            label: "        BACK       ",
            y: window.innerHeight * 8 / 14,
            x: Q.width / 2,
            fill: "#F5F5F5",
            //border: 1,
            scale: 0.8
        }, function () {
            Q.clearStage(2);
            //Q.clearStage(3);
            Q.stageScene("option", 2);
            }));

        if (sessionStorage.getItem("difficulty") == "easy") {
            easy.p.fill = "#808080";
            medium.p.fill = "#F5F5F5";
            hard.p.fill = "#F5F5F5";
        } else if (sessionStorage.getItem("difficulty") == "medium") {
            easy.p.fill = "#F5F5F5";
            medium.p.fill = "#808080";
            hard.p.fill = "#F5F5F5";
        } else {
            easy.p.fill = "#F5F5F5";
            medium.p.fill = "#F5F5F5";
            hard.p.fill = "#808080";
        }
    })

    // Score
    Q.scene('hud', function (stage) {
        var container = stage.insert(new Q.UI.Container({
            x: 0, y: 0
        }));
        var score = container.insert(new Q.UI.Text({
            x: window.innerWidth/2, y: 20,
            label: "0", color: "white", align: "right"
        }));

        var lives = container.insert(new Q.UI.Text({
            x: window.innerWidth / 2, y: 50,
            label: "\u2764\u2764\u2764", color: "white", align: "left",
        }));
    });

    //Scene Game
    Q.scene("level1", function (stage) {
        bgSelector = Math.floor(Math.random() * 3);
        //console.log(bgSelector);
        switch (bgSelector) {
            case 0:
                stage.insert(new Q.Repeater({
                    asset: "bg.jpg",
                    speedY: 1.5, speedX: 0, type: 0
                }));
                break;
            case 1:
                stage.insert(new Q.Repeater({
                    asset: "bg1.jpg",
                    speedY: 1.5, speedX: 0, type: 0
                }));
                break;
            case 2:
                stage.insert(new Q.Repeater({
                    asset: "bg2.jpg",
                    speedY: 1.5, speedX: 0, type: 0
                }));
                break;
            default:
                console.log("Error. Failed to load the background.");
                break;
        }
        // insert Player
        var player = stage.insert(new Q.Player());
        /*stage.insert(new Q.Enemy2({ y: 100}));
        stage.insert(new Q.Enemy1({ y: -800, counter: 0 }));
        stage.insert(new Q.Enemy1({ y: -700, counter: 20 * (Math.PI * 2 / 300) }));
        stage.insert(new Q.Enemy1({ y: -600, counter: 40 * (Math.PI * 2 / 300) }));
        stage.insert(new Q.Enemy1({ y: -500, counter: 60 * (Math.PI * 2 / 300) }));
        stage.insert(new Q.Enemy1({ y: -400, counter: 80 * (Math.PI * 2 / 300) }));*/
        stage.add("viewport")/*.follow(player)*/;
        st = stage;
    });

    //******************************//
    //***********PLAYER*************//
    //******************************//

    Q.component("playerControl", {
        defaults: { speed: 0, direction: 'up' },

        added: function () {
            var p = this.entity.p;

            // add in our default properties
            Q._defaults(p, this.defaults);

            // every time our entity steps
            // call our step method
            this.entity.on("step", this, "step");
            if (!tryAgain) {
                Q.input.on("fire", this, "blaster");
                Q.input.on("menuB", this, "menuTrigger");
                Q.input.on("continue", this, "conTrigger");
            }
        },
        step: function (dt) {
            // grab the entity's properties
            // for easy reference
            var p = this.entity.p;
            var randomEvent = Math.floor(Math.random() * 1);

            if (p.y >= window.innerHeight - 120) {
                p.y -= 6;
            }

            if (Q("Asteroidbelt1").length == 0 && Q("Asteroidbelt2").length == 0) {
                var randomNumberOfAsteroids = Math.floor(Math.random() * 6) + 1;
                for (var i = 0; i < randomNumberOfAsteroids; i++) {
                    var randomAsteriod = Math.floor(Math.random() * 2);
                    switch (randomAsteriod) {
                        case 0:
                            st.insert(new Q.Asteroidbelt1());
                            break;
                        case 1:
                            st.insert(new Q.Asteroidbelt2());
                            break;
                        default:
                            break;
                    }
                }
            }
            
            if (Q("Asteroids").length == 0) {
                var randomNumberOfAsteroids = Math.floor(Math.random() * 2) + 1;
                for (var i = 0; i < randomNumberOfAsteroids; i++) {
                    st.insert(new Q.Asteroids());
                }
            }
            
            if (p.score % 1000 != 0) {
                temp = 1;
            }

            if (p.score % 1000 == 0 && p.score > 0 && temp != 0) {
                gameStage++;
                if (gameStage % 5 == 0) {
                    health++;
                }
                temp = 0;
            }
            
            if (Q("Enemy1").length == 0 && Q("Enemy2").length == 0) {
                var randomEnemy = Math.floor(Math.random() * 2);
                var scoreNum = p.score;
                var enemy1 = Q("Enemy1");
                var enemy2 = Q("Enemy2");

                if (scoreNum >= 1000 && scoreNum <= 1350) {
                    st.insert(new Q.plusBlaster());
                } else if (scoreNum >= 2000 && scoreNum <= 2800) {
                    st.insert(new Q.plusBlasterSpeed());
                }

                if (sessionStorage.getItem("difficulty") == "easy") {
                    var dif = -1;
                    var speed = -1.2;
                } else if (sessionStorage.getItem("difficulty") == "medium") {
                    var dif = 0;
                    var speed = 0;
                } else {
                    var dif = 2;
                    var speed = 1.8;
                }

                if (scoreNum >= 1000 && scoreNum <= 1350) {
                    st.insert(new Q.Enemy2({ x: window.innerWidth / 4, y: -100, hitPoints: 22+dif, moveSet: 3, score: 200 }));
                    st.insert(new Q.Enemy2({ x: window.innerWidth * 3 / 4, y: -100, hitPoints: 22+dif, moveSet: 3, score: 200 }));
                } else if (scoreNum >= 2000 && scoreNum <= 2800) {
                    for (var i = 0; i < 5; i++) {
                        for (var k = 1; k <= 2; k++) {
                            st.insert(new Q.Enemy1({ x: (window.innerWidth / 10) + ((window.innerWidth) / 5 * i) - 20, y: -100 * k, defaultX: (window.innerWidth / 10) + ((window.innerWidth) / 5 * i) - 20, defaultY: -100 * k, hitPoints: 5+dif, moveSet: 4, score: 100 }));
                        }
                    }
                } else {
                    switch (randomEnemy) {
                        case 0:
                            var randomNumOfEnemys = 1;
                            if (p.score > 4000) {
                                randomNumOfEnemys = Math.floor(Math.random() * 2);
                            }
                            for (var i = 0; i < randomNumOfEnemys; i++) {
                                st.insert(new Q.Enemy2({ x: Math.floor(Math.random() * (window.innerWidth - 180)) + 80, y: -100, hitPoints: 7+dif + health, speed: 2.2 + speed }));
                            }
                            break;
                        case 1:
                            var randomWay = Math.floor(Math.random() * 3) - 1;
                            var randomX = window.innerWidth / 2;
                            if (randomWay == 0) {
                                randomX = Math.floor(Math.random() * (window.innerWidth - 180)) + 80;
                            } else if (randomWay == 1) {
                                randomX = window.innerWidth / 2 + 100;
                            } else if (randomWay == -1) {
                                randomX = window.innerWidth / 2 - 100;
                            }
                            var y = 4;
                            for (var i = 1; i <= gameStage + 1; i++) {
                                st.insert(new Q.Enemy1({ x: randomX, y: -100 * i, counter: y -= 1 * 20 * (Math.PI * 2 / 300), way: randomWay, hitPoints: 2 + dif + health, speed: 4 + speed }));
                            }
                            break;
                        default:
                            break;
                    }
                }
            }
            
            if (p.immune) {
                if (op) {
                    p.opacity -= 0.05;
                    if (p.opacity <= 0.5) {
                        op = false;
                    }
                } else{
                    p.opacity += 0.05;
                    if (p.opacity >= 1) {
                        op = true;
                    }
                }
                if (p.immuneTimer <= 144) {
                    p.immuneTimer++;
                    if (p.immuneTimer == 144) {
                        p.immune = false;
                        p.opacity = 1;
                    }
                    
                }
            }
            pPx = p.x;
            pPy = p.y;
            var speed = 4.8;
            if (Q.inputs['left']) {
                if (p.x > 30) {
                    p.x -= speed;
                    //p.angle = 90; 
                }
            }
            if (Q.inputs['right']) {
                if (p.x < window.innerWidth - 30) {
                    p.x += speed;
                    //p.angle = 270;  
                }
            }

            if (gunSet != p.gunSet/* && fireB == true*/) {
                this.blaster();
            }
            if (blasterSpeed != p.blasterSpeed/* && fireB == true*/) {
                this.blaster();
            }
            /*if (Q.inputs['fire']) {
                if (!fireB) {
                    intervalB = window.setInterval(fire, intervalBValue);
                    fireB = true;
                }
            } else {
                    clearInterval(intervalB);
                    fireB = false;
            }*/
        },
        blaster: function (dt) {
            //console.log(fireB);
            var ep = this.entity.p;
            //clearInterval(intervalB);
            if (!p) {
                if (!fireB) {
                    gunSet = ep.gunSet;
                    blasterSpeed = ep.blasterSpeed;
                    if (gunSet == 1) {
                        intervalB = window.setInterval(fire, intervalBValue + ep.blasterSpeed);
                    } else {
                        intervalB = window.setInterval(fire, intervalBValue);
                    }

                } else {
                    clearInterval(intervalB);
                }
                fireB = !fireB;
            }
        },
        menuTrigger: function (dt) {
            menuB();
        },
        conTrigger: function (dt) {
            continueB();
        }
    });

    Q.component("blasterControl", {
        added: function () {
            var p = this.entity.p;
            
            // every time our entity steps
            // call our step method
            this.entity.on("step", this, "step");
        },
        step: function (dt) {
            var p = this.entity.p;
            p.angle = -90;
            p.y -= 10;
            if (p.y < -1) {
                //console.log("outOfScene");
                this.entity.del("blasterControl");
                this.entity.debind();
                this.entity.destroy();
            }
            
        }
    });

    // Player START

    Q.Sprite.extend("Player", {
        init: function (p) {
            this._super(p,
                {
                    //sheet: "player",
                    x: window.innerWidth / 2,
                    y: window.innerHeight + 20,
                    hitPoints: 3,
                    asset: 'rocket.png',
                    scale: 0.08,
                    score: 0,
                    opacity: 1,
                    gunSet: 0,
                    blasterSpeed: 40,
                    type: Q.SPRITE_PLAYER,
                    collisionMask: Q.SPRITE_POWERUP
                });
            
            this.add('playerControl');

        }
    });

    Q.Sprite.extend("Blaster", {
        init: function (p) {
            this._super(p, {
                x: pPx,
                y: pPy - 24,
                damage: 1,
                asset: 'bullet.png',
                type: Q.SPRITE_FRIENDLY,
                collisionMask: Q.SPRITE_ENEMY
            });
            this.add("2d, blasterControl");
        }
    });

    //Player END

});