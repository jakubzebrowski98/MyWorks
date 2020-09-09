<?php
  session_start();
  //blokada przed wejściem na strone bez uprawnień
  if(isset($_SESSION['logged']['email'])){
    //header('location: ./scripts/login.php');
  }
?>
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <title>Gamer Shop | Home</title>
  <!-- Tell the browser to be responsive to screen width -->
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link href="https://fonts.googleapis.com/css2?family=Anton&display=swap" rel="stylesheet">
  <link href="https://fonts.googleapis.com/css2?family=Anton&family=MuseoModerno:wght@300&display=swap" rel="stylesheet">
  <link rel="stylesheet" href="../main.css">
</head>
<body class="hold-transition register-page">
  <div class="home-box">
    <div class="koszyk-all">
      <!-- Interaktywny przycisk logo sklepu -->
      <a class="logo" href="../index.php">FutureDesk</a>
    <?php
        //Wyświetlanie nazwy użytkownika
        if(isset($_SESSION['logged']['email'])){?>
          <div class = "user">Witaj : <?php echo $_SESSION['logged']['name'];
          if($_SESSION['logged']['permission']==1) echo " (Admin)"; ?></div>
          <?php
          
        }
        else echo "<div class = 'user2'>Zaloguj się aby dokończyć zakupy</div>";
    ?>
    <div class="card">
      <?php
        //Przycisk zaloguj
        if(isset($_SESSION['logged']['email'])){
          echo '<a href="../scripts/logout.php" class="zarejestruj2">Wyloguj</a>';
        }
        else echo '<a href="../login_page.php" class="zaloguj2">Zaloguj</a>';
      ?>
      <?php
        //łączenie się z bazą i sprawdzenie czy działa
        require_once '../scripts/connect.php';
        if($conn->connect_errno){
          $_SESSION['error'] = 'Błąd łączenia z bazą danych!';
          exit();
        }

        //zapytanie zwracające produkty
        $sql = "SELECT  id, name, price, image FROM `produkty`";
        $stmt = $conn->prepare($sql);
        $stmt->bind_result($id, $name, $price, $image);
        $stmt->execute();
        $stmt->fetch();
        //header("Content-type: image/png");
        $tab_name = explode(" ", $name);

        //usuwanie produktów z kosszyka
        function serve_post(){
            if(isset($_POST['product-'])){
                $product = $_POST['product-'];
                if($_SESSION['product'][$product]==1) unset($_SESSION['product'][$product]);
                else $_SESSION['product'][$product]--;
                header("Refresh:0");
            }
          }
        
        //wyświtlanie w tabeli, produktów dodanych do koszyka
        function generate_cart(){
            echo "   
            <form action = '' class = 'card' method = 'post'>
            <table class='koszyk2' border='3px solid'>
            <br><caption><br>Koszyk</caption>
            <th>Nr.</the><th>Produkt</th><th>Ilosc</th><th>Usuń</th>
            ";
            $i=0;
          
            if(isset($_SESSION['product'])){
                foreach($_SESSION['product'] as $key=>$n){
                    $i++;
                        echo "
                        <tr>
                        <td>$i</td><td>$key</td><td>$n</td>
                        <td><input type='submit' name='product-' value='$key' class='delete'></td>
                        ";
                    }
            }
            //nie działa
            else{
              echo "<div class = 'user'>Twój koszyk jest pusty</div>";
            }
        }

        //przycisk powrotu do porzedniej strony
        echo '<form action="../index.php" method="post">';
          echo "<input type='submit' class = 'zarejestruj2' name='Return' value='Powrót'>";
        echo '</form>';

        //uruchomienie funkcji generowania talbicy koszyka i usuwania produktów
        generate_cart();
        serve_post();

        //zamknięcie połączenia z bazą
        $stmt->close();
        $conn->close();
      ?>
    </div>
  </div>
      </div>
</body>
</html>
