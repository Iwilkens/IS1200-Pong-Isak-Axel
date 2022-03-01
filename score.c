


int score_player1 = 0;
int score_player2 = 0;

void score (player)
{
  if(player == 1)
  {
    score_player1 += 1;
    display_string("Player one: score!")
    display_update();
    delay(2000);
  }
  else if (player == 2)
  {
    score_player2 += 1;
    display_string("Player two: score!")
    display_update();
    delay(2000);
  }
}
