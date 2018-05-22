Quintus.Enemy = function (Q) {
    //Enemy START
    var sounds
    function fire(xp, yp, moveSet) {
        if (Q.stage(1).paused != null) {
            if (moveSet == 1 || moveSet == 4) {
                if (sounds) {
                    var b = Q.audio.play('blaster1.wav');
                }
                Q.stage(1).insert(new Q.enemyBlaster({ x: xp, y: yp + 23 }));
            } else if (moveSet == 2 || moveSet == 3) {
                if (sounds) {
                    var b = Q.audio.play('blaster1.wav');
                }
                Q.stage(1).insert(new Q.enemyBlaster({ x: xp+15, y: yp + 23 }));
                Q.stage(1).insert(new Q.enemyBlaster({ x: xp-15, y: yp + 23 }));
            }
        }
    }

    Q.component("enemyControl", {
        added: function () {
            var entity = this.entity;
            var p = this.entity.p;
            entity.on("bump.bottom, bump.left, bump.right", function (collision) {
                if (collision.obj.isA("Player")) {
                    if (!collision.obj.p.immune) {
                        //console.log(collision.obj.p.hitPoints);
                        if (p.sounds) {
                            Q.audio.play('explosion.wav');
                            if (collision.obj.p.hitPoints != 1) {
                                Q.audio.play('alert.wav');
                            } else {
                                Q.audio.play('gameOver.wav');
                            }
                        }
                        collision.obj.p.hitPoints -= p.damage;
                        var livesLabel = Q("UI.Text", 3).items[1];
                        var livesnum = 0, hearts = "";
                        while (livesnum < collision.obj.p.hitPoints) {
                            hearts += "\u2764";
                            livesnum++;
                        }
                        collision.obj.p.immune = true;
                        collision.obj.p.immuneTimer = 0;
                        //collision.obj.p.opacity = 0.5;
                        if (collision.obj.p.hitPoints == 0) {
                            //hearts = "DEAD";
                            collision.obj.debind();
                            collision.obj.destroy();
                            Q.stage(1).pause();
                            Q.clearStage(1);
                            Q.clearStage(2);
                            Q.input.disableTouchControls();
                            Q.stageScene("end", 1);

                        }
                        if (entity.p.moveSet == 5) {
                            entity.destroy();
                        }

                        livesLabel.p.label = hearts;
                        //console.log("kek");
                        //entity.destroy();
                    }
                    
                }

                if (collision.obj.isA("Blaster")) {
                    //console.log(collision.obj.p.damage);
                    collision.obj.destroy();
                    var player = Q("Player").first();
                    p.hitPoints -= collision.obj.p.damage;
                    //entity.p.opacity = 0.5;
                    entity.p.hit = true;
                    entity.p.hitTimer = 0;
                    if (p.hitPoints == 0) {
                        entity.destroy();
                        if (p.sounds) {
                            var random = Math.floor(Math.random() * 3);
                            switch (random) {
                                case 0:
                                    Q.audio.play('explosion.wav');
                                    break;
                                case 1:
                                    Q.audio.play('explosion2.wav');
                                    break;
                                case 2:
                                    Q.audio.play('explosion3.wav');
                                    break;
                                default:
                                    break;
                            }
                        }
                        player.p.score += entity.p.score;
                        var scoreLabel = Q("UI.Text", 3).items[0];
                        scoreLabel.p.label = player.p.score.toString();
                    } else {
                        if (p.sounds) {
                            var random = Math.floor(Math.random() * 4);
                            switch (random) {
                                case 0:
                                    Q.audio.play('hit1.wav');
                                    break;
                                case 1:
                                    Q.audio.play('hit2.wav');
                                    break;
                                case 2:
                                    Q.audio.play('hit3.wav');
                                    break;
                                case 3:
                                    Q.audio.play('hit4.wav');
                                    break;
                                default:
                                    break;
                            }
                        }
                    }
                    //console.log(p.hitPoints);
                    //console.log("hit");
                }
            });
            this.entity.on("step", this, "step");
            
        },
        step: function (dt) {
            var entity = this.entity;
            var p = this.entity.p;
            sounds = p.sounds;
            if (this.entity.p.hit) {
                this.entity.p.hitTimer++
                if (this.entity.p.hitTimer <= 4) {
                    this.entity.p.opacity = 0.7;
                } else {
                    this.entity.p.opacity = 1;
                }
            }
            if (p.moveSet == 1) {
                var randomVoiceTrue = Math.floor(Math.random() * 2500) + 1;
                var randomVoice;
                if (p.sound) {
                    if (randomVoiceTrue == 1) {
                        randomVoice = Math.floor(Math.random() * 12) + 1;
                        console.log(randomVoice);
                    }
                    switch (randomVoice) {
                        case 1:
                            Q.audio.play("aliens-radio-chatter1.wav");
                            break;
                        case 2:
                            Q.audio.play("aliens-radio-chatter2.wav");
                            break;
                        case 3:
                            Q.audio.play("aliens-radio-chatter3.wav");
                            break;
                        case 4:
                            Q.audio.play("aliens-radio-chatter4.wav");
                            break;
                        case 5:
                            Q.audio.play("aliens-radio-chatter5.wav");
                            break;
                        case 6:
                            Q.audio.play("aliens-radio-chatter6.wav");
                            break;
                        case 7:
                            Q.audio.play("aliens-radio-chatter7.wav");
                            break;
                        case 8:
                            Q.audio.play("aliens-radio-chatter8.wav");
                            break;
                        case 9:
                            Q.audio.play("aliens-radio-chatter9.wav");
                            break;
                        case 10:
                            Q.audio.play("aliens-radio-chatter10.wav");
                            break;
                        case 11:
                            Q.audio.play("aliens-radio-chatter11.wav");
                            break;
                        case 12:
                            Q.audio.play("aliens-radio-chatter12.wav");
                            break;
                        default:
                            break;
                    }
                }

                p.y += p.speed;
                var enemyFire = Math.floor(Math.random() * 300) + 1;
                var increase = Math.PI * 2 / 300;
                p.x += /*window.innerWidth / 2 +*/ p.way * Math.sin(p.counter) / 0.5;
                p.counter += increase;


            } else if (p.moveSet == 2) {
                p.y += p.speed;
                var enemyFire = Math.floor(Math.random() * 150) + 1;
                if (p.sounds) {
                    var sound = Math.floor(Math.random() * 1500) + 1;
                    if (sound == 1) {
                        Q.audio.play('firstMiniBoss2.wav');
                    } else if (sound == 750) {
                        Q.audio.play('firstMiniBoss1.wav');
                    }
                }
            } else if (p.moveSet == 3) {
                if (p.y <= 100) {
                    p.y += p.speed;
                } else {
                    var enemyFire = Math.floor(Math.random() * 150) + 1;
                }
                if (p.sounds) {
                    var sound = Math.floor(Math.random() * 1000) + 1;
                    if (sound == 1) {
                        Q.audio.play('firstMiniBoss2.wav');
                    } else if (sound == 500) {
                        Q.audio.play('firstMiniBoss1.wav');
                    }
                }
            } else if (p.moveSet == 4) {
                if (p.y == 200) {
                    var increase = Math.PI * 2 / 400;
                    p.x += /*window.innerWidth / 2 +*/ p.way * Math.sin(p.counter) / 6;
                    p.counter += increase;
                } else {
                    var increase = Math.PI * 2 / 400;
                    p.x += /*window.innerWidth / 2 +*/ p.way * Math.sin(p.counter) / 4.0;
                    p.counter += increase;
                }

                if (p.defaultY + 300 != p.y) {
                    p.y += 5;
                } else {
                    var enemyFire = Math.floor(Math.random() * 250) + 1;
                }
            } else if (p.moveSet == 5) {
                p.y += p.speed;
                //entity.play("stand");
                p.angle += p.rotationSpeed;
            }

            if (p.y > window.innerHeight + 80) {
                //console.log("enemyOutOfScene");
                this.entity.del("enemyControl");
                this.entity.debind();
                this.entity.destroy();
            }

            if (enemyFire == 1 && p.y <= window.innerHeight - 80 && p.y >= 10) {
                fire(p.x, p.y, p.moveSet);
            }
        }
    });


    Q.component("enemyBlasterControl", {
        added: function () {
            var p = this.entity.p;

            // every time our entity steps
            // call our step method
            this.entity.on("step", this, "step");
        },
        step: function (dt) {
            var p = this.entity.p;
            var entity = this.entity; 
            sounds = p.sounds;
            p.y += 10;
            if (p.y > window.innerHeight + 80) {
                //console.log("outOfScene");
                this.entity.del("blasterControl");
                this.entity.debind();
                this.entity.destroy();
            }
            entity.on("bump.bottom, bump.left, bump.right", function (collision) {
                if (collision.obj.isA("Player")) {
                    if (!collision.obj.p.immune) {
                        //console.log(collision.obj.p.hitPoints);
                        if (p.sounds) {
                            Q.audio.play('explosion.wav');
                            if (collision.obj.p.hitPoints != 1) {
                                Q.audio.play('alert.wav');
                            } else {
                                Q.audio.play('gameOver.wav');
                            }
                        }
                        collision.obj.p.hitPoints -= p.damage;
                        var livesLabel = Q("UI.Text", 3).items[1];
                        var livesnum = 0, hearts = "";
                        while (livesnum < collision.obj.p.hitPoints) {
                            hearts += "\u2764";
                            livesnum++;
                        }
                        collision.obj.p.immune = true;
                        collision.obj.p.immuneTimer = 0;
                        //collision.obj.p.opacity = 0.5;
                        if (collision.obj.p.hitPoints == 0) {
                            //hearts = "DEAD";
                            collision.obj.destroy();
                            collision.obj.debind();
                            Q.stage(1).pause();
                            Q.clearStage(1);
                            Q.clearStage(2);
                            Q.input.disableTouchControls();
                            Q.stageScene("end", 1);

                        }
                        livesLabel.p.label = hearts;
                        //console.log("kek");
                        entity.destroy();
                    }
                }
            });
        }
    });

    Q.Sprite.extend("Enemy1", {
        init: function (p) {
            this._super(p, {
                x: window.innerWidth / 2,
                y: -1 * (Math.floor(Math.random() * 300) + 100),
                hitPoints: 2,
                damage: 1,
                counter: 0,
                moveSet: 1,
                score: 50,
                asset: 'Enemy1.png',
                scale: 0.05,
                way: 1,
                defaulX: 0,
                defaulY: 0,
                speed: 4,
                type: Q.SPRITE_ENEMY,
                collisionMask: Q.SPRITE_PLAYER,
                sounds: sessionStorage.getItem("sounds") == 'true' ? true : false
            });
            this.p.angle = 90;
            this.add("2d, enemyControl");
            this.on("bump.bottom, bump.left, bump.right", function (collision) {
                if (collision.obj.isA("Player")) {
                    this.p.collisionMask = Q.SPRITE_ENEMY;
                }
            });
        }

    });

    Q.Sprite.extend("Enemy2", {
        init: function (p) {
            this._super(p, {
                x: window.innerWidth / 4,
                y: -1 * (Math.floor(Math.random() * 300) + 100),
                hitPoints: 9,
                damage: 1,
                counter: 0,
                moveSet: 2,
                score: 100,
                asset: 'Enemy2.png',
                scale: 0.06,
                speed: 2.2,
                type: Q.SPRITE_ENEMY,
                collisionMask: Q.SPRITE_PLAYER,
                sounds: sessionStorage.getItem("sounds") == 'true' ? true : false
            });
            this.p.angle = 180;
            this.add("2d, enemyControl");
            this.on("bump.bottom, bump.left, bump.right", function (collision) {
                if (collision.obj.isA("Player")) {
                    this.p.collisionMask = Q.SPRITE_ENEMY;
                }
            });
        }

    });

    Q.Sprite.extend("enemyBlaster", {
        init: function (p) {
            this._super(p, {
                x: 100,
                y: 0,
                damage: 1,
                angle: 90,
                asset: 'bulletE.png',
                type: Q.SPRITE_ENEMY,
                sounds: sessionStorage.getItem("sounds") == 'true' ? true : false
            });
            this.add("2d, enemyBlasterControl");
            this.on("bump.bottom, bump.left, bump.right", function (collision) {
                if (collision.obj.isA("Player")) {
                    this.p.collisionMask = Q.SPRITE_ENEMY;
                }
            });
        }
    });

    //Enemy END
}
