<!-- Strona do wyrzucenia - tylko do testów -->

<?php
  session_start();
  //blokada przed wejściem na strone bez uprawnień - można wywalić
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

  <link rel="stylesheet" href="../main.css">
</head>
<body class="hold-transition register-page">

  <div class="home-box">
    <div class="logo">
      <!-- Interaktywny przycisk logo sklepu -->
      <a href="../"><b>Gamer </b>Shop</a>
    </div>
    <!--Wyświetlanie nazwy użytkownika - tu by trzeba było dać jakiś div żeby było oddzielone od reszty strony-->
    Jesteś zalogowany jako: Gość
    <div class="card">
      <!-- Przycisk Zaloguj -->
      <a href="../login_page.php" class="text-center">Login</a>
    </div>
  </div>

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

    //pętla do wyświetlenia tego samego produktu 9x - trzeba to wpakować w jakieś divy
    echo  '<form action="" method="post">';
    $num=0;
    for($ci=0; $ci<3; $ci++){
      for($c=0; $c<3; $c++){
        echo "<br>";
        echo '<img id="img1" src="data:image/jpeg;base64,'.base64_encode( $image ).'"/>';
        echo  " ", $num, " ", $id, " ", $name, " ", $price, " ";
        echo "<input type='submit' name='product' value='$tab_name[0], $num'";
        $num++;
      }
      echo "<br>";
    }
    echo "</form>";
    if(isset($_POST['product'])){
      $product = $_POST['product'];
      if(!isset($_SESSION['product'][$product])) $_SESSION['product'][$product] = 1;
      else $_SESSION['product'][$product]++;
    }

    echo '<form action="./koszyk.php" method="post">';
    echo "<input type='submit' name='product' value='Koszyk'>";
    echo '</form>';

    


    //zamknięcie połączenia z bazą
    $stmt->close();
    $conn->close();
  ?>

</body>
</html>
