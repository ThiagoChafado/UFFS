
package cadastrofilmes;
import java.util.ArrayList;
import java.util.List;
import javax.swing.JOptionPane;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;


public class TelaCadastro extends javax.swing.JFrame {
    private List<Filme> filmes;

    public TelaCadastro() {
        initComponents();
        filmes = new ArrayList<>();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        buttonGroup1 = new javax.swing.ButtonGroup();
        jPanel1 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        edtTitulo = new javax.swing.JTextField();
        edtOriginal = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        taSinopse = new javax.swing.JTextArea();
        jLabel4 = new javax.swing.JLabel();
        edtDuracao = new javax.swing.JTextField();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        rbLivre = new javax.swing.JRadioButton();
        rb14anos = new javax.swing.JRadioButton();
        rb16anos = new javax.swing.JRadioButton();
        rb18anos = new javax.swing.JRadioButton();
        btnCadastrar = new javax.swing.JToggleButton();
        jPanel2 = new javax.swing.JPanel();
        jLabel7 = new javax.swing.JLabel();
        cbAcao = new javax.swing.JCheckBox();
        cbAventura = new javax.swing.JCheckBox();
        cbComedia = new javax.swing.JCheckBox();
        cbDrama = new javax.swing.JCheckBox();
        cbSuspense = new javax.swing.JCheckBox();
        cbTerror = new javax.swing.JCheckBox();
        jLabel8 = new javax.swing.JLabel();
        ccPais = new javax.swing.JComboBox<>();
        btnMostrarFilmes = new javax.swing.JButton();
        btnFiltrarFilmes = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Cadastro de Filme");
        setBackground(new java.awt.Color(255, 255, 255));

        jPanel1.setBorder(javax.swing.BorderFactory.createTitledBorder("Informações Básicas"));

        jLabel1.setText("Título");

        jLabel2.setText("Título Original");

        edtOriginal.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                edtOriginalActionPerformed(evt);
            }
        });

        jLabel3.setText("Sinopse");

        taSinopse.setColumns(20);
        taSinopse.setRows(5);
        jScrollPane1.setViewportView(taSinopse);

        jLabel4.setText("Duração");

        jLabel5.setText("Minutos");

        jLabel6.setText("Classificação");

        buttonGroup1.add(rbLivre);
        rbLivre.setSelected(true);
        rbLivre.setText("Livre");
        rbLivre.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                rbLivreActionPerformed(evt);
            }
        });

        buttonGroup1.add(rb14anos);
        rb14anos.setText("14 anos");

        buttonGroup1.add(rb16anos);
        rb16anos.setText("16 anos");

        buttonGroup1.add(rb18anos);
        rb18anos.setText("18 anos");
        rb18anos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                rb18anosActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jScrollPane1)
                        .addContainerGap())
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel1)
                            .addComponent(edtTitulo, javax.swing.GroupLayout.PREFERRED_SIZE, 210, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel2)
                            .addComponent(edtOriginal, javax.swing.GroupLayout.PREFERRED_SIZE, 210, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(78, 78, 78))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel3)
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addComponent(jLabel4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addComponent(edtDuracao, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jLabel5)
                                .addGap(57, 57, 57)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(jPanel1Layout.createSequentialGroup()
                                        .addComponent(rbLivre)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(rb14anos)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(rb16anos)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(rb18anos))
                                    .addComponent(jLabel6))))
                        .addContainerGap(202, Short.MAX_VALUE))))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(jLabel2))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(edtTitulo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(edtOriginal, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel3)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4)
                    .addComponent(jLabel6))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jLabel5)
                        .addComponent(rbLivre)
                        .addComponent(rb14anos)
                        .addComponent(rb16anos)
                        .addComponent(rb18anos))
                    .addComponent(edtDuracao, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(21, Short.MAX_VALUE))
        );

        btnCadastrar.setText("Cadastrar");
        btnCadastrar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCadastrarActionPerformed(evt);
            }
        });

        jPanel2.setBorder(javax.swing.BorderFactory.createTitledBorder("Outras Informações"));

        jLabel7.setText("Gênero");

        cbAcao.setText("Ação");

        cbAventura.setText("Aventura");
        cbAventura.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cbAventuraActionPerformed(evt);
            }
        });

        cbComedia.setText("Comédia");

        cbDrama.setText("Drama");

        cbSuspense.setText("Suspense");

        cbTerror.setText("Terror");

        jLabel8.setText("País de origem");

        ccPais.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Brasil\t", "Estados Unidos", "Argentina", "Inglaterra", "Canadá" }));
        ccPais.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ccPaisActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel7)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addComponent(cbAcao)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(cbAventura)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(cbComedia)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(cbDrama)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(cbSuspense)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(cbTerror))
                    .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                        .addComponent(ccPais, javax.swing.GroupLayout.Alignment.LEADING, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jLabel8, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel7)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(cbAcao)
                    .addComponent(cbAventura)
                    .addComponent(cbComedia)
                    .addComponent(cbDrama)
                    .addComponent(cbSuspense)
                    .addComponent(cbTerror))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel8)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(ccPais, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(12, Short.MAX_VALUE))
        );

        btnMostrarFilmes.setText("MostrarFilmes");
        btnMostrarFilmes.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnMostrarFilmesActionPerformed(evt);
            }
        });

        btnFiltrarFilmes.setText("FiltrarFilmes");
        btnFiltrarFilmes.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnFiltrarFilmesActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(btnMostrarFilmes)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(btnFiltrarFilmes)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(btnCadastrar)
                .addContainerGap())
            .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnCadastrar)
                    .addComponent(btnMostrarFilmes)
                    .addComponent(btnFiltrarFilmes))
                .addContainerGap())
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void edtOriginalActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_edtOriginalActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_edtOriginalActionPerformed

    private void btnCadastrarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCadastrarActionPerformed
        int classificacao;
        String titulo = edtTitulo.getText();
        String original = edtOriginal.getText();
        String sinopse = taSinopse.getText();
        
            int duracao = Integer.parseInt(edtDuracao.getText());
        
            
        
        String generos = "";
        
        if (rbLivre.isSelected()){
            classificacao=0;
        }else if(rb14anos.isSelected()){
            classificacao=1;
        }else if(rb16anos.isSelected()){
            classificacao=2;
        }else{
            classificacao=3;
        }
        
        if (cbAcao.isSelected()){
            generos += "Ação ";
        }if(cbAventura.isSelected()){
            generos += "Aventura ";
        }if (cbComedia.isSelected()){
            generos += "Comédia ";
        }if(cbDrama.isSelected()){
            generos += "Drama ";
        }if(cbSuspense.isSelected()){
            generos += "Suspense ";
        }if(cbTerror.isSelected()){
            generos += "Terror ";
        }
        
        
        int pais = ccPais.getSelectedIndex();
        String paisDeOrigem = (String) ccPais.getSelectedItem();
        String msg = "Título: "+ titulo + "\n";
        //msg +=  "Título oririnal: "+ original + "\n";
        //msg +=  "Sinopse: "+ sinopse + "\n";
        
       // msg +=  "Duração: "+ duracao + "\n";
       // msg +=  "Classificação: "+ classificacao + "\n";
       // msg +=  "Gêneros: "+ generos + "\n";
        //msg +=  "País de origem: "+ paisDeOrigem + "\n";
        
      //  JOptionPane.showMessageDialog(null,msg);
        Filme f = new Filme(titulo,original,sinopse);
        
        filmes.add(f);
        
        JOptionPane.showMessageDialog(null, "Filme cadastrado com sucesso");
        
        // TODO add your handling code here:
    }//GEN-LAST:event_btnCadastrarActionPerformed

    private void rb18anosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_rb18anosActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_rb18anosActionPerformed

    private void cbAventuraActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cbAventuraActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_cbAventuraActionPerformed

    private void ccPaisActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ccPaisActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_ccPaisActionPerformed

    private void rbLivreActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_rbLivreActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_rbLivreActionPerformed

    private void btnMostrarFilmesActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnMostrarFilmesActionPerformed
        String msg ="";
        int cont=0;
        
        for (Filme f : filmes){
            msg += "Filme " + cont + "\n";
            msg += "Titulo: " + f.getTitulo()+ "\n";
            msg += "Titulo Original: " + f.getTituloOriginal()+ "\n";
            msg += "Sinopse: " + f.getSinopse()+ "\n";
            msg += "----------------------------\n";
            cont++;
            
        }
        JOptionPane.showMessageDialog(null,msg);
        
        
        // TODO add your handling code here:
    }//GEN-LAST:event_btnMostrarFilmesActionPerformed

    private void btnFiltrarFilmesActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnFiltrarFilmesActionPerformed
            TelaFiltragem t = new TelaFiltragem(filmes);
            t.setVisible(true);


        // TODO add your handling code here:
    }//GEN-LAST:event_btnFiltrarFilmesActionPerformed
    public static void main(String args[]) throws InstantiationException, IllegalAccessException, UnsupportedLookAndFeelException {
        try{
            javax.swing.UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
            
        }
        catch(ClassNotFoundException ex){
            
        }
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new TelaCadastro().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JToggleButton btnCadastrar;
    private javax.swing.JButton btnFiltrarFilmes;
    private javax.swing.JButton btnMostrarFilmes;
    private javax.swing.ButtonGroup buttonGroup1;
    private javax.swing.JCheckBox cbAcao;
    private javax.swing.JCheckBox cbAventura;
    private javax.swing.JCheckBox cbComedia;
    private javax.swing.JCheckBox cbDrama;
    private javax.swing.JCheckBox cbSuspense;
    private javax.swing.JCheckBox cbTerror;
    private javax.swing.JComboBox<String> ccPais;
    private javax.swing.JTextField edtDuracao;
    private javax.swing.JTextField edtOriginal;
    private javax.swing.JTextField edtTitulo;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JRadioButton rb14anos;
    private javax.swing.JRadioButton rb16anos;
    private javax.swing.JRadioButton rb18anos;
    private javax.swing.JRadioButton rbLivre;
    private javax.swing.JTextArea taSinopse;
    // End of variables declaration//GEN-END:variables
}
