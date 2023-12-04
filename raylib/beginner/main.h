int screenHeight = 450;
int screenWidth = 800;

//SPRITE
class Sprite{
    public:
        double x, y, radius;
        bool falling = true;
        double g = 0.1;
        double velocity = 0;
    
    Sprite(double x, double y, int radius){
        this->x = x;
        this->y = y;
        this->radius = radius;
    }

    void updateSprite(){
        y -= velocity;
        DrawCircle(x, y, radius, WHITE);
    }

    void gravity(){
        if(falling)
            velocity -= 0.01;
            updateSprite();
    }

    void goUp(){
        bool goUp = IsKeyPressed(KEY_UP);
        if(goUp){/*w*/
            velocity = 0;
            falling = false;
            int end = y - 30;
            double increment = 0.005;
            goUp = false;
            while(y > end){ 
                velocity += increment;
                updateSprite();
            }
            while(velocity > 0){
                velocity -= increment;
            }
            falling = true;
        }
    }
};

class Column {
    public:
        float speed = 1;
        Rectangle pillarA;
        Rectangle pillarB;
        int serialno, isPositive;
        double gap;
        int posX;

    Column(int serialno) {
        this->serialno = serialno;
        gap = rand() % 50 + 10;
        isPositive = rand() % 2;
        if(isPositive == 1){
            gap -= gap*2;
        }
        posX = 850 + serialno*150;
        pillarA = {posX, 0, 60 , screenHeight/2 - 65 + gap};
        pillarB = {posX,screenHeight - (screenHeight/2 - 65 - gap ), 60,  screenHeight/2 - 65 - gap};
    }

    void move() {
        pillarA.x -= speed;
        pillarB.x -= speed;
    }

    void reset(){
        if(pillarA.x < -80){
            pillarA.x = 840;
            pillarB.x = 840;
            //randomise
            gap = rand() % 50 + 10;
            isPositive = rand() % 2;
            if(isPositive == 1){
            gap -= gap*2;
            }

            pillarA.height = screenHeight/2 - 65 + gap;
            pillarB.y = screenHeight - (screenHeight/2 - 65 - gap );
            pillarB.height = screenHeight/2 - 65 - gap;

        }
    }

    void draw(){
        if(pillarA.x < 900 && pillarA.x > -80 ){
            DrawRectangleRec(pillarA, GREEN);
            DrawRectangleRec(pillarB, GREEN);
        }
    }
};