import java.util.Scanner;

class Cajero {
    private static double saldo = 10000.0;
    private static int nip = 1234;

    public static double getSaldo() {
        return saldo;
    }

    public static void setSaldo(double nuevoSaldo) {
        saldo = nuevoSaldo;
    }

    public static int getNIP() {
        return nip;
    }

    public static void setNIP(int nuevoNIP) {
        nip = nuevoNIP;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int opcion;

        do {
            System.out.println("***** Cajero Automático CREDIFÁCIL *****\n");
            System.out.println("Seleccione alguna de las siguientes opciones:");
            System.out.println("1. Retiro de dinero");
            System.out.println("2. Consulta de saldo");
            System.out.println("3. Cambio de NIP");
            System.out.println("4. Salir\n");

            if (scanner.hasNextInt()) {
                opcion = scanner.nextInt();
                switch (opcion) {
                    case 1:
                        RetiroDeDinero.retirarDinero();
                        break;
                    case 2:
                        ConsultaDeSaldo.consultarSaldo();
                        break;
                    case 3:
                        CambioDeNIP.cambiarNIP();
                        break;
                    case 4:
                        System.out.println("Gracias por utilizar nuestro cajero automático. ¡Hasta luego!");
                        break;
                    default:
                        System.out.println("Opción inválida. Por favor, seleccione una opción válida.\n");
                        break;
                }
            } else {
                String input = scanner.nextLine();
                System.out.println("Valor inválido. Ingrese un valor correcto.\n");
                opcion = 0;
            }
        } while (opcion != 4);
    }
}

class RetiroDeDinero {
    public static void retirarDinero() {
        Scanner scanner = new Scanner(System.in);

        System.out.println("RETIRO DE DINERO");
        System.out.print("Ingrese la cantidad a retirar: ");
        double cantidadRetiro = scanner.nextDouble();

        // Validación de datos
        while (cantidadRetiro <= 0 || cantidadRetiro > Cajero.getSaldo()) {
            System.out.println("Cantidad inválida. Por favor, ingrese una cantidad válida.");
            System.out.print("Ingrese la cantidad a retirar: ");
            cantidadRetiro = scanner.nextDouble();
        }

        System.out.println("¿Está seguro de que desea retirar $" + cantidadRetiro + "? (S/N)");
        String confirmacion = scanner.next();

        if (confirmacion.equalsIgnoreCase("S")) {
            double nuevoSaldo = Cajero.getSaldo() - cantidadRetiro;
            Cajero.setSaldo(nuevoSaldo);
            System.out.println("Retiro exitoso. Se ha retirado $" + cantidadRetiro);
            System.out.println("Saldo restante: $" + Cajero.getSaldo());
        } else {
            System.out.println("Retiro cancelado. No se ha retirado ningún monto.");
        }
    }
}

class ConsultaDeSaldo {
    public static void consultarSaldo() {
        System.out.println("Consulta de saldo");
        System.out.println("Saldo actual: $" + Cajero.getSaldo());
    }
}

class CambioDeNIP {
    public static void cambiarNIP() {
        Scanner scanner = new Scanner(System.in);

        System.out.println("CAMBIO DE NIP");
        System.out.print("Ingrese el NIP anterior: ");
        int nipAnterior = scanner.nextInt();

        // Validación de NIP
        while (nipAnterior != Cajero.getNIP()) {
            System.out.println("NIP incorrecto. Por favor, ingrese el NIP correcto.");
            System.out.print("Ingrese el NIP anterior: ");
            nipAnterior = scanner.nextInt();
        }

        System.out.print("Ingrese el nuevo NIP: ");
        int nuevoNIP = scanner.nextInt();
        System.out.print("Confirme el nuevo NIP: ");
        int confirmacionNIP = scanner.nextInt();

        // Validación de NIP
        while (nuevoNIP != confirmacionNIP) {
            System.out.println("Los NIP no coinciden. Por favor, vuelva a ingresar los NIP.");
            System.out.print("Ingrese el nuevo NIP: ");
            nuevoNIP = scanner.nextInt();
            System.out.print("Confirme el nuevo NIP: ");
            confirmacionNIP = scanner.nextInt();
        }

        Cajero.setNIP(nuevoNIP);
        System.out.println("NIP cambiado exitosamente.");
    }
}