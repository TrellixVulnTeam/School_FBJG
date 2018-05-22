Quintus.Asteroid = function (Q) {
    Q.component("asteroidControl", {
        added: function () {
            
            this.entity.on("step", this, "step");
        },
        step: function(dt) {
            this.entity.p.y += 1.5;
            if (this.entity.p.y > window.innerHeight + 80) {
                //console.log("asteroidOutOfScene");
                this.entity.del("asteroidControl");
                this.entity.debind();
                this.entity.destroy();
            }
        }

    });

    Q.component("asteroidsControl", {
        added: function () {

            //this.entity.on("step", this, "step");
            this.entity.play("stand");
        }
    });

    Q.Sprite.extend("Asteroidbelt1", {
        init: function (p) {
            this._super(p, {
                x: Math.floor(Math.random() * (window.innerWidth - 40)) + 20,
                y: -100,
                asset: 'asteroid_belt.png',
                scale: 0.08,
                type: Q.SPRITE_NONE
            });
            this.add("asteroidControl");
            this.p.angle = Math.floor(Math.random() * 360);
        }
    });
    Q.Sprite.extend("Asteroidbelt2", {
        init: function (p) {
            this._super(p, {
                x: Math.floor(Math.random() * (window.innerWidth - 40)) + 20,
                y: -100,
                asset: 'asteroid_belt2.png',
                scale: 0.08,
                type: Q.SPRITE_NONE
            });
            this.add("2d, asteroidControl");
            this.p.angle = Math.floor(Math.random() * 360);
        }
    });

    Q.Sprite.extend("Asteroids", {
        init: function (p) {
            this._super(p, {
                x: Math.floor(Math.random() * (window.innerWidth - 40)) + 20,
                y: -100,
                hitPoints: 3,
                damage: 1,
                counter: 0,
                moveSet: 5,
                score: 10,
                sprite: "asteroid",
                sheet: "asteroid",
                //asset: 'asteroids.png',
                scale: 0.8,
                speed: Math.floor(Math.random() * 2.2) + 0.4,
                rotationSpeed: Math.floor(Math.random() * 200) / 100,
                type: Q.SPRITE_ENEMY,
                collisionMask: Q.SPRITE_PLAYER,
                sounds: sessionStorage.getItem("sounds") == 'true' ? true : false
            });
            Q.animations('asteroid', {
                stand: { frames: [Math.floor(Math.random() * 5)], rate: 0 }
            });
            //this.p.play("stand");
            this.add("2d, animation, enemyControl, asteroidsControl");
            this.on("bump.bottom, bump.left, bump.right", function (collision) {
                if (collision.obj.isA("Player")) {
                    this.p.collisionMask = Q.SPRITE_ENEMY;
                }
            });
            //this.p.angle = 180;
            this.p.angle = Math.floor(Math.random() * 360);
        }
    });

    /*
    Q.animations('asteroid', {
        run: { frames: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10], rate: 1 / 10 },
        stand: { frames: [7], rate: 0 }

    });*/

}
